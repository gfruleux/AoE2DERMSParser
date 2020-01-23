import argparse

from gui.MainFrame import MainFrame
from parsers.ParserGeneratingObjects import ParserGeneratingObjects
from parsers.ParserMapConstFiles import ParserMapConstFiles


def run(main_frame, logger):
    logger("----------\n[START] AoE2 DE RMS Parsing\n")
    try:
        logger("Parsing GeneratingObjects.inc ...")
        pgo = ParserGeneratingObjects(main_frame.path_gen_obj)
        table_gen_objects = pgo.get_result()

        logger("Parsing Map Const files ...")
        pmcf = ParserMapConstFiles(main_frame.path_rms_files, [main_frame.get_map_size_key()])
        dict_gen_const_by_map = pmcf.get_result()
        for map_name in dict_gen_const_by_map:
            final_file_name = "Cleaned_" + main_frame.get_map_size_reformat() + "_" + map_name
            with open(main_frame.path_out_dir + "/" + final_file_name, "w") as fp_write:
                logger("\nStart Writing file " + final_file_name + " ... ")
                table_const = dict_gen_const_by_map[map_name]
                # ### Write Cleaned file
                for elt in table_gen_objects:
                    display = elt.display(table_const)
                    fp_write.write(display)
                logger("End Writing file " + final_file_name)

    except (RuntimeError, TypeError) as err:
        logger("Oops an error occurred ...")
        logger("{0}".format(err))
        return False

    logger("\n[END] AoE2 DE RMS Parsing\n")
    return True


def main(args):
    main_frame = MainFrame(run, args.gen, args.out, args.rms, args.size)
    if not args.cmd:
        main_frame.draw()
    else:
        run(main_frame, print)


if __name__ == '__main__':
    arg_parse = argparse.ArgumentParser(description="Parser for AoE2 DE RandomMapScript.",
                                        epilog="You can use either the GUI or the command line.\nYou can provide the "
                                               "arguments to the GUI, but in order to run from command line make sure "
                                               "to set --cmd and fill at least -gen, -out and -rms options.")
    arg_parse.add_argument("-c", "--cmd", help="Run this program without GUI with the provided args.",
                           action="store_true")
    arg_parse.add_argument("-gen", metavar="\"Path/to/GeneratingObjects.inc\"", default=None,
                           help="Path of the GeneratingObjects.inc file from AoE2", )
    arg_parse.add_argument("-out", metavar="\"Path/output/directory\"", default=None,
                           help="Path of the Output directory for the parsed files")
    arg_parse.add_argument("-rms", nargs="+", metavar="\"Path/to/.rms files\"", default=None,
                           help="List of path of the RMS files to parse")
    arg_parse.add_argument("-size", metavar="One of the possible map size", default="",
                           help="Available attributes are: TINY_MAP, SMALL_MAP, MEDIUM_MAP, LARGE_MAP, HUGE_MAP, "
                                "GIGANTIC_MAP, LUDIKRIS_MAP or nothing for Normal maps")
    args_dict = arg_parse.parse_args()

    if args_dict.cmd and (args_dict.gen is None or args_dict.out is None or args_dict.rms is None):
        exit("You must provide -gen, -out and -rms when using --cmd")

    main(args_dict)
