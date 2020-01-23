import tkinter as tk
from tkinter import ttk, filedialog as dial
from tkinter.scrolledtext import ScrolledText

from const.File import FILE_OPTION_GEN, FILE_OPTION_RMS
from const.Map import MAP_SIZE_DICT


class MainFrame:
    def __init__(self, runner, path_gen=None, path_out=None, path_rms=None, map_size=None):
        self.runner = runner
        self.root = tk.Tk()
        self.path_gen_obj: str or None = path_gen
        self.path_out_dir: str or None = path_out
        self.path_rms_files: list or None = path_rms
        self._map_size: str or None = map_size
        self.ptr_scroll = None

    def get_map_size_key(self):
        return self._map_size

    def get_map_size_reformat(self):
        if self._map_size is None or self._map_size == "":
            return "NORMAL_MAP"
        else:
            return self._map_size

    def log(self, msg):
        self.ptr_scroll.insert(tk.END, msg + "\n")

    def run(self):
        self.ptr_scroll.configure(state='normal')
        self.runner(self, self.log)
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

        self.root.title("AoE2 DE RMS Parser")
        # Map Type
        tk.Label(self.root, text="Select Map Size").grid(row=0, column=0)
        var_map_size = tk.StringVar()
        combo_map_size = ttk.Combobox(self.root, values=list(MAP_SIZE_DICT.keys()), justify="center",
                                      textvariable=var_map_size)
        combo_map_size.bind("<<ComboboxSelected>>",
                            lambda event: update_map_size(lbl_map_size, var_map_size.get()))
        combo_map_size.grid(row=0, column=1)
        combo_map_size.current(3)
        lbl_map_size = tk.Label(self.root, text="Not selected")
        lbl_map_size.grid(row=1, column=0, columnspan=1)

        # GeneratingObjects.inc
        tk.Label(self.root, text="Select GeneratingObjects.inc").grid(row=3, column=0)
        btn_gen_obj = ttk.Button(self.root, text="Browse", command=lambda: update_gen_obj(lbl_gen_obj, FILE_OPTION_GEN))
        btn_gen_obj.grid(row=3, column=1)
        lbl_gen_obj = tk.Label(self.root, text=self.path_gen_obj or "Not selected")
        lbl_gen_obj.grid(row=4, column=0, columnspan=1)

        # Output Dir
        tk.Label(self.root, text="Select Output directory").grid(row=6, column=0)
        btn_out_dir = ttk.Button(self.root, text="Browse", command=lambda: update_out_dir(lbl_out_dir))
        btn_out_dir.grid(row=6, column=1)
        lbl_out_dir = tk.Label(self.root, text=self.path_out_dir or "Not selected")
        lbl_out_dir.grid(row=7, column=0, columnspan=1)

        # RMS files
        tk.Label(self.root, text="Select RMS files to parse").grid(row=9, column=0)
        btn_rms = ttk.Button(self.root, text="Browse", command=lambda: update_rms(lbl_rms, FILE_OPTION_RMS))
        btn_rms.grid(row=9, column=1)
        lbl_rms = ttk.Label(self.root, text=self.path_rms_files or "Not selected")
        lbl_rms.grid(row=10, column=0, columnspan=1)

        # Run
        btn_run = ttk.Button(self.root, text="Run", command=lambda: self.run())
        btn_run.grid(row=12, column=0, columnspan=1)
        scroll_log = ScrolledText()
        scroll_log.grid(row=13, column=0, columnspan=1)
        scroll_log.configure(state='disabled')
        self.ptr_scroll = scroll_log

        self.root.mainloop()
