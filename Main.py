import argparse
import os
import logging

from gui.MainFrame import MainFrame
from parsers.ParserGeneratingObjects import ParserGeneratingObjects
from parsers.ParserMapConstFiles import ParserMapConstFiles


def run(main_frame):
    logging.info("----------\n[START] AoE2 DE RMS Parsing\n")
    try:
        logging.info("Parsing GeneratingObjects.inc ...")
        pgo = ParserGeneratingObjects(main_frame.path_gen_obj)
        gen_objects_list = pgo.get_result()

        logging.info("Parsing Map Const files ...")
        pmcf = ParserMapConstFiles(main_frame.path_rms_files, [main_frame.get_map_size_key(),
                                                               main_frame.get_map_res_key(),
                                                               main_frame.get_map_type_key()])
        dict_gen_const_by_map = pmcf.get_result()
        logging.info("\nOutput dir set to " + main_frame.path_out_dir)
        for map_name in dict_gen_const_by_map:
            final_file_name = "Cleaned_" + main_frame.get_map_size_reformat() + main_frame.get_map_res_reformat() + \
                              main_frame.get_map_type_reformat() + map_name
            with open(main_frame.path_out_dir + os.path.sep + final_file_name, "w") as fp_write:
                logging.info("\nStart Writing file " + final_file_name)
                table_const = dict_gen_const_by_map[map_name]
                # ### Write Cleaned file
                for elt in gen_objects_list:
                    display = elt.display(table_const)
                    fp_write.write(display)
                logging.info("End Writing file " + final_file_name)

    except (RuntimeError, TypeError) as err:
        logging.critical("Oops an error occurred ...")
        logging.critical("{0}".format(err))
        return False

    logging.info("\n[END] AoE2 DE RMS Parsing\n")
    return True


def main(args):
    main_frame = MainFrame(run, args.gen, args.out, args.rms, args.size, args.type, args.infinite)
    if not args.cmd:
        main_frame.draw()
    else:
        run(main_frame)


if __name__ == '__main__':
    arg_parse = argparse.ArgumentParser(description="Parser for AoE2 DE RandomMapScript.",
                                        epilog="You can use either the GUI or the command line.\nYou can provide the "
                                               "arguments to the GUI, but in order to run from command line make sure "
                                               "to set --cmd and fill at least -gen, -out and -rms options.")
    arg_parse.add_argument("-c", "--cmd", help="Run this program without GUI with the provided args.",
                           action="store_true")
    # Required args if -c passed
    arg_parse.add_argument("-gen", metavar="\"Path/to/GeneratingObjects.inc\"", default=None,
                           help="Path of the GeneratingObjects.inc file from AoE2")
    arg_parse.add_argument("-out", metavar="\"Path/output/directory\"", default=None,
                           help="Path of the Output directory for the parsed files")
    arg_parse.add_argument("-rms", nargs="+", metavar="\"Path/to/.rms files\"", default=None,
                           help="List of path of the RMS files to parse")
    # Always optional args
    arg_parse.add_argument("-i", "--infinite", help="Set the Map Resources to Infinite", action="store_true")
    arg_parse.add_argument("-size", metavar="One of the possible map sizes", default="",
                           help="Available attributes are: TINY_MAP, SMALL_MAP, MEDIUM_MAP, LARGE_MAP, HUGE_MAP, "
                                "GIGANTIC_MAP, LUDIKRIS_MAP or nothing for Normal maps")
    arg_parse.add_argument("-type", metavar="One of the possible map types", default="",
                           help="Available attributes are: KING_OT_HILL, EMPIRE_WARS, BATTLE_ROYALE, REGICIDE"
                                " or nothing for Normal maps")
    args_dict = arg_parse.parse_args()

    if args_dict.cmd and (args_dict.gen is None or args_dict.out is None or args_dict.rms is None):
        exit("You must provide at least -gen, -out and -rms when using --cmd")

    main(args_dict)
