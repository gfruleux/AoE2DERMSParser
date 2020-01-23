import tkinter as tk
from tkinter import ttk, filedialog as dial
from tkinter.scrolledtext import ScrolledText

from const.File import FILE_OPTION_GEN, FILE_OPTION_RMS
from parsers.ParserGeneratingObjects import ParserGeneratingObjects
from parsers.ParserMapConstFiles import ParserMapConstFiles


class MainFrame:
    def __init__(self):
        self.path_gen_obj: str or None = None
        self.path_out_dir: str or None = None
        self.path_rms_files: list or None = None
        self.ptr_scroll = None

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

        self.root = tk.Tk()
        self.root.title("AoE2 DE RMS Parser")

        # GeneratingObjects.inc
        tk.Label(self.root, text="Select GeneratingObjects.inc").grid(row=3, column=0)
        btn_gen_obj = ttk.Button(self.root, text="Browse", command=lambda: update_gen_obj(lbl_gen_obj, FILE_OPTION_GEN))
        btn_gen_obj.grid(row=3, column=1)
        lbl_gen_obj = tk.Label(self.root, text="Not selected")
        lbl_gen_obj.grid(row=4, column=0, columnspan=1)

        # Output Dir
        tk.Label(self.root, text="Select Output directory").grid(row=6, column=0)
        btn_out_dir = ttk.Button(self.root, text="Browse", command=lambda: update_out_dir(lbl_out_dir))
        btn_out_dir.grid(row=6, column=1)
        lbl_out_dir = tk.Label(self.root, text="Not selected")
        lbl_out_dir.grid(row=7, column=0, columnspan=1)

        # RMS files
        tk.Label(self.root, text="Select RMS files to parse").grid(row=9, column=0)
        btn_rms = ttk.Button(self.root, text="Browse", command=lambda: update_rms(lbl_rms, FILE_OPTION_RMS))
        btn_rms.grid(row=9, column=1)
        lbl_rms = ttk.Label(self.root, text="Not selected")
        lbl_rms.grid(row=10, column=0, columnspan=1)

        # Run
        btn_run = ttk.Button(self.root, text="Run", command=lambda: self.run())
        btn_run.grid(row=12, column=0, columnspan=1)
        scroll_log = ScrolledText()
        scroll_log.grid(row=13, column=0, columnspan=1)
        self.ptr_scroll = scroll_log

        self.root.mainloop()

    def log(self, msg):
        self.ptr_scroll.insert(tk.END, msg + "\n")

    def run(self):
        self.ptr_scroll.configure(state='normal')
        try:
            self.log("Parsing GeneratingObjects.inc ...")
            pgo = ParserGeneratingObjects(self.path_gen_obj)
            table_gen_objects = pgo.get_result()

            self.log("Parsing Map Const files ...")
            pmcf = ParserMapConstFiles(self.path_rms_files)
            dict_gen_const_by_map = pmcf.get_result()

            for map_name in dict_gen_const_by_map:
                with open(self.path_out_dir + "/Cleaned_" + map_name, "w") as fp_write:
                    self.log("Start Writing file Cleaned_" + map_name + " ... ")
                    table_const = dict_gen_const_by_map[map_name]
                    # ### Write Cleaned file
                    for elt in table_gen_objects:
                        display = elt.display(table_const)
                        fp_write.write(display)
                    self.log("End Writing file Cleaned_" + map_name)

        except (RuntimeError, TypeError) as err:
            self.log("Oops an error occurred ...")
            self.log("{0}".format(err))
        self.ptr_scroll.configure(state='disabled')
