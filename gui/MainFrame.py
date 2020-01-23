import tkinter as tk
import tkinter.font as tkfont
from tkinter import ttk, filedialog as dial
from tkinter.scrolledtext import ScrolledText

from const.File import FILE_OPTION_GEN, FILE_OPTION_RMS
from const.Map import MAP_SIZE_DICT, MAP_RESOURCES_DICT, MAP_SIZE_IDX


class MainFrame:
    def __init__(self, runner, path_gen=None, path_out=None, path_rms=None, map_size=None, map_resources=False):
        self.runner = runner
        self.root = tk.Tk()
        self.path_gen_obj: str or None = path_gen
        self.path_out_dir: str or None = path_out
        self.path_rms_files: list or None = path_rms
        self._map_size: str or None = map_size
        self._map_resources: int or None = "INFINITE_RESOURCES" if map_resources else None
        self.ptr_scroll = None

    def get_map_size_key(self):
        return self._map_size

    def get_map_size_reformat(self):
        if self._map_size is None or self._map_size == "":
            return "NORMAL_MAP"
        else:
            return self._map_size

    def get_map_res_key(self):
        return self._map_resources

    def get_map_res_reformat(self):
        if self._map_resources is None or self._map_resources == "":
            return "NORMAL_RES"
        else:
            return self._map_resources

    def log(self, msg):
        self.ptr_scroll.insert(tk.END, msg + "\n")

    def run(self, ptr_btn):
        self.ptr_scroll.configure(state='normal')
        result = self.runner(self, self.log)
        if not result:
            ptr_btn.config(bg="red")
        else:
            ptr_btn.config(bg="green")
        self.ptr_scroll.configure(state='disabled')

    def draw(self):
        def ask_file(file_option):
            return dial.askopenfilename(**file_option)

        def update_gen_obj(ptr_label, options):
            self.path_gen_obj = ask_file(options)
            ptr_label.config(text=self.path_gen_obj)

        def update_out_dir(ptr_label):
            self.path_out_dir = dial.askdirectory()
            ptr_label.config(text=self.path_out_dir)

        def update_rms(ptr_label, options):
            file_path_tuples = ask_file(options)
            self.path_rms_files = list(file_path_tuples)
            ptr_label.config(text="\n".join(self.path_rms_files))

        def update_map_size(ptr_label, map_size_key: str):
            self._map_size = MAP_SIZE_DICT[map_size_key]
            ptr_label.config(text=self._map_size)

        def update_map_resources(map_res_key: str):
            self._map_resources = MAP_RESOURCES_DICT[map_res_key]

        self.root.title("AoE2 DE RMS Parser")

        helv10b = tkfont.Font(family='Helvetica', size=10, weight='bold')
        # Map Resources
        tk.Label(self.root, text="Is Infinite Resources mod ?", font=helv10b, bg="lightblue") \
            .grid(row=0, column=0)
        var_map_res = tk.StringVar()
        combo_map_res = ttk.Combobox(self.root, values=list(MAP_RESOURCES_DICT.keys()), justify="center",
                                     textvariable=var_map_res)
        combo_map_res.bind("<<ComboboxSelected>>",
                           lambda event: update_map_resources(var_map_res.get()))
        combo_map_res.grid(row=0, column=1)
        combo_map_res.current(1 if self._map_resources is None or self._map_resources == "" else 0)

        # Map Type
        tk.Label(self.root, text="Select Map Size", font=helv10b, bg="lightblue") \
            .grid(row=1, column=0)
        var_map_size = tk.StringVar()
        combo_map_size = ttk.Combobox(self.root, values=list(MAP_SIZE_DICT.keys()), justify="center",
                                      textvariable=var_map_size)
        combo_map_size.bind("<<ComboboxSelected>>",
                            lambda event: update_map_size(lbl_map_size, var_map_size.get()))
        combo_map_size.grid(row=1, column=1)
        if self._map_size is not None:
            lbl_map_size_txt = self._map_size
            combo_map_size.current(MAP_SIZE_IDX[self._map_size])
        else:
            lbl_map_size_txt = "Not selected"
        lbl_map_size = tk.Label(self.root, text=lbl_map_size_txt)
        lbl_map_size.grid(row=2, column=0, columnspan=2)

        # GeneratingObjects.inc
        tk.Label(self.root, text="Select GeneratingObjects.inc", font=helv10b, bg="lightblue") \
            .grid(row=3, column=0)
        btn_gen_obj = tk.Button(self.root, text="Browse", command=lambda: update_gen_obj(lbl_gen_obj, FILE_OPTION_GEN))
        btn_gen_obj.grid(row=3, column=1)
        lbl_gen_obj = tk.Label(self.root, text=self.path_gen_obj or "Not selected")
        lbl_gen_obj.grid(row=4, column=0, columnspan=2)

        # Output Dir
        tk.Label(self.root, text="Select Output directory", font=helv10b, bg="lightblue") \
            .grid(row=5, column=0)
        btn_out_dir = tk.Button(self.root, text="Browse", command=lambda: update_out_dir(lbl_out_dir))
        btn_out_dir.grid(row=5, column=1)
        lbl_out_dir = tk.Label(self.root, text=self.path_out_dir or "Not selected")
        lbl_out_dir.grid(row=6, column=0, columnspan=2)

        # RMS files
        tk.Label(self.root, text="Select RMS files to parse", font=helv10b, bg="lightblue") \
            .grid(row=7, column=0)
        btn_rms = tk.Button(self.root, text="Browse", command=lambda: update_rms(lbl_rms, FILE_OPTION_RMS))
        btn_rms.grid(row=7, column=1)
        lbl_rms = tk.Label(self.root, text=self.path_rms_files or "Not selected")
        lbl_rms.grid(row=8, column=0, columnspan=2)

        # Run
        btn_run = tk.Button(self.root, text="Run", command=lambda: self.run(btn_run))
        btn_run.grid(row=9, column=0, columnspan=2)
        scroll_log = ScrolledText(height=12)
        scroll_log.grid(row=10, column=0, columnspan=2)
        scroll_log.configure(state='disabled')
        self.ptr_scroll = scroll_log

        self.root.mainloop()
