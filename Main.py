import tkinter
from tkinter import filedialog

from const.File import FILE_OPTION_GEN, FILE_OPTION_RMS
from parsers.ParserGeneratingObjects import ParserGeneratingObjects
from parsers.ParserMapConstFiles import ParserMapConstFiles


def main(dir_path: str = None, file_gen_path: str = None, file_path_list: list = None):
    # ### Parse GeneratingObjects.inc from AoE 2
    if file_gen_path is None:
        file_gen_path = tkinter.filedialog.askopenfilename(**FILE_OPTION_GEN)
    if file_gen_path == "":
        exit("No file provided (Required GeneratingObjects.inc)")
    pgo = ParserGeneratingObjects(file_gen_path)
    table_gen_objects = pgo.get_result()

    # ### Parse Map Const files
    if file_path_list is None:
        file_path_tuples = tkinter.filedialog.askopenfilenames(**FILE_OPTION_RMS)
        file_path_list = list(file_path_tuples)
    if len(file_gen_path) == 0:
        exit("No files provided (Required RMS)")
    pmcf = ParserMapConstFiles(file_path_list)
    dict_gen_const_by_map = pmcf.get_result()

    # ### Output
    if dir_path is None:
        dir_path = tkinter.filedialog.askdirectory()
    if dir_path == "":
        exit("No Output Directory provided (Required)")
    for map_name in dict_gen_const_by_map:
        with open(dir_path + "/Cleaned_" + map_name, "w") as fp_write:
            table_const = dict_gen_const_by_map[map_name]
            # ### Write Cleaned file
            for elt in table_gen_objects:
                display = elt.display(table_const)
                fp_write.write(display)


if __name__ == '__main__':
    main()
