import ntpath
import os
import tkinter as tk
import tkinter.font as tkfont
from tkinter import ttk, filedialog as dial
from tkinter.scrolledtext import ScrolledText

from const import FILE_OPTION_GEN, FILE_OPTION_RMS
from aoe2de_rms_gen_obj_parser.const import *


def ask_file(file_option):
    return dial.askopenfilename(**file_option)


def get_key(dictionary, value):
    for k, v in dictionary.items():
        if v == value:
            return k
    return None


class MainFrame:
    def __init__(self, adapter):  # , path_gen, path_out, path_rms, map_size, map_type, map_resources):
        self.adapter = adapter
        self.root = tk.Tk()
        # Private paths
        self._path_gen_obj = None
        self._path_rms_file_list = None
        self._path_out_dir = None
        # Pointers for labels text update
        self._ptr_lbl_gen_obj = None
        self._ptr_lbl_out_dir = None
        self._ptr_lbl_rms_files = None
        self._ptr_lbl_map_size = None
        self._ptr_lbl_map_resources = None
        self._ptr_lbl_game_type = None
        # Pointers for parsing updates
        self._ptr_scroll = None
        self._ptr_btn_run = None
        self._btn_default_color = None

    def update_gen_obj(self):
        path_gen_obj = ask_file(FILE_OPTION_GEN)
        self._ptr_lbl_gen_obj.config(text=path_gen_obj)
        self.adapter.update_path_gen_obj(path_gen_obj)

    def update_out_dir(self):
        self._path_out_dir = dial.askdirectory()
        self._ptr_lbl_out_dir.config(text=self._path_out_dir)

    def update_rms(self):
        file_path_tuples = ask_file(FILE_OPTION_RMS)
        self._path_rms_file_list = list(file_path_tuples)
        self._ptr_lbl_rms_files.config(text="\n".join(self._path_rms_file_list))

    def update_map_size(self, map_size_value: str):
        map_size_key = get_key(MAP_SIZE_DICT, map_size_value)
        self._ptr_lbl_map_size.config(text=map_size_key)
        self.adapter.update_map_size(map_size_key)

    def update_map_resources(self, map_resources_value: str):
        map_resources_key = get_key(MAP_RESOURCES_DICT, map_resources_value)
        self._ptr_lbl_map_resources.config(text=map_resources_key)
        self.adapter.update_map_resources(map_resources_key)

    def update_game_type(self, game_type_value: str):
        game_type_key = get_key(GAME_TYPE_DICT, game_type_value)
        self._ptr_lbl_game_type.config(text=game_type_key)
        self.adapter.update_game_type(game_type_key)

    def log(self, msg):
        self._ptr_scroll.insert(tk.END, msg + "\n")

    def run(self):
        self._ptr_scroll.configure(state="normal")
        self._ptr_btn_run.config(bg=self._btn_default_color)

        try:
            self.log("¤¤¤ Start of the parsing ... \n")
            for path_rms_file in self._path_rms_file_list:
                file_name = self._get_output_filename(path_rms_file)
                self.log("Parsing " + path_rms_file)
                self.adapter.update_path_rms_file(path_rms_file)
                with open(self._path_out_dir + os.path.sep + file_name, "w") as fp:
                    content = self.adapter.parse()
                    fp.write(content)
                    self.log("Parsed file written.")

            self.log("\n¤¤¤ End of the parsing ! \n\n")
            self._ptr_btn_run.config(bg="green")

        except BaseException as e:
            print(e)
            self.log("\nSomething went wrong :/\n")
            self.log(str(e))
            self._ptr_btn_run.config(bg="red")

        self._ptr_scroll.configure(state="disabled")

    def _get_output_filename(self, file_path):
        head, tail = ntpath.split(file_path)
        file_name = tail or ntpath.basename(head)
        return file_name

    def draw(self):
        self.root.title("AoE2 Definitive Edition RandomMapScript Parser")

        helv10b = tkfont.Font(family='Helvetica', size=10, weight='bold')
        row_index = 0

        # ### Map Resources
        tk.Label(self.root, text="Select Map Resources", font=helv10b, bg="lightblue") \
            .grid(row=row_index, column=0)
        var_map_res = tk.StringVar()
        combo_map_res = ttk.Combobox(self.root, values=list(MAP_RESOURCES_DICT.values()), justify="center",
                                     textvariable=var_map_res)
        combo_map_res.bind("<<ComboboxSelected>>", lambda event: self.update_map_resources(var_map_res.get()))
        combo_map_res.grid(row=row_index, column=1)
        combo_map_res.current(0)
        row_index += 1
        lbl_map_res_txt = get_dict_first_key(MAP_RESOURCES_DICT)
        lbl_map_res = tk.Label(self.root, text=lbl_map_res_txt)
        lbl_map_res.grid(row=row_index, column=0, columnspan=2)
        self._ptr_lbl_map_resources = lbl_map_res

        # ### Map Size
        row_index += 1
        tk.Label(self.root, text="Select Map Size", font=helv10b, bg="lightblue") \
            .grid(row=row_index, column=0)
        var_map_size = tk.StringVar()
        combo_map_size = ttk.Combobox(self.root, values=list(MAP_SIZE_DICT.values()), justify="center",
                                      textvariable=var_map_size)
        combo_map_size.bind("<<ComboboxSelected>>", lambda event: self.update_map_size(var_map_size.get()))
        combo_map_size.grid(row=row_index, column=1)
        combo_map_size.current(0)
        row_index += 1
        lbl_map_size_txt = get_dict_first_key(MAP_SIZE_DICT)
        lbl_map_size = tk.Label(self.root, text=lbl_map_size_txt)
        lbl_map_size.grid(row=row_index, column=0, columnspan=2)
        self._ptr_lbl_map_size = lbl_map_size

        # ### Game Type
        row_index += 1
        tk.Label(self.root, text="Select Game Type", font=helv10b, bg="lightblue") \
            .grid(row=row_index, column=0)
        var_game_type = tk.StringVar()
        combo_gamme_type = ttk.Combobox(self.root, values=list(GAME_TYPE_DICT.values()), justify="center",
                                        textvariable=var_game_type)
        combo_gamme_type.bind("<<ComboboxSelected>>", lambda event: self.update_game_type(var_game_type.get()))
        combo_gamme_type.grid(row=row_index, column=1)
        combo_gamme_type.current(0)
        row_index += 1
        lbl_game_type_txt = get_dict_first_key(GAME_TYPE_DICT)
        lbl_game_type = tk.Label(self.root, text=lbl_game_type_txt)
        lbl_game_type.grid(row=row_index, column=0, columnspan=2)
        self._ptr_lbl_game_type = lbl_game_type

        # ### GeneratingObjects.inc
        row_index += 1
        tk.Label(self.root, text="Select GeneratingObjects.inc", font=helv10b, bg="lightblue") \
            .grid(row=row_index, column=0)
        btn_gen_obj = tk.Button(self.root, text="Browse", command=lambda: self.update_gen_obj())
        btn_gen_obj.grid(row=row_index, column=1)
        row_index += 1
        lbl_gen_obj = tk.Label(self.root, text=self._path_gen_obj or "Not selected")
        lbl_gen_obj.grid(row=row_index, column=0, columnspan=2)
        self._ptr_lbl_gen_obj = lbl_gen_obj

        # ### Output Dir
        row_index += 1
        tk.Label(self.root, text="Select Output directory", font=helv10b, bg="lightblue") \
            .grid(row=row_index, column=0)
        btn_out_dir = tk.Button(self.root, text="Browse", command=lambda: self.update_out_dir())
        btn_out_dir.grid(row=row_index, column=1)
        row_index += 1
        lbl_out_dir = tk.Label(self.root, text=self._path_out_dir or "Not selected")
        lbl_out_dir.grid(row=row_index, column=0, columnspan=2)
        self._ptr_lbl_out_dir = lbl_out_dir

        # ### RMS files
        row_index += 1
        tk.Label(self.root, text="Select RMS files to parse", font=helv10b, bg="lightblue") \
            .grid(row=row_index, column=0)
        btn_rms = tk.Button(self.root, text="Browse", command=lambda: self.update_rms())
        btn_rms.grid(row=row_index, column=1)
        row_index += 1
        lbl_rms_files = tk.Label(self.root, text=self._path_rms_file_list or "Not selected")
        lbl_rms_files.grid(row=row_index, column=0, columnspan=2)
        self._ptr_lbl_rms_files = lbl_rms_files

        # ### Run
        row_index += 1
        btn_run = tk.Button(self.root, text="Run", command=lambda: self.run())
        btn_run.grid(row=row_index, column=0, columnspan=2)
        self._ptr_btn_run = btn_run
        self._btn_default_color = self._ptr_btn_run.cget("background")
        # ### Logging ScrollText
        row_index += 1
        scroll_log = ScrolledText(height=12)
        scroll_log.grid(row=row_index, column=0, columnspan=2)
        scroll_log.configure(state='disabled')
        self._ptr_scroll = scroll_log

        self.root.mainloop()
