from aoe2de_rms_gen_obj_parser import GeneratingObjectsParser

from frame import MainFrame


class ParserAdapter:
    def __init__(self):
        self._generating_object_parser = GeneratingObjectsParser()

    def update_path_gen_obj(self, path_gen_obj):
        self._generating_object_parser.set_path_gen_obj(path_gen_obj)

    def update_path_rms_file(self, path_rms_file):
        self._generating_object_parser.set_path_rms_file(path_rms_file)

    def update_map_size(self, map_size):
        self._generating_object_parser.set_map_size(map_size)

    def update_map_resources(self, map_resources):
        self._generating_object_parser.set_map_resources(map_resources)

    def update_game_type(self, game_type):
        self._generating_object_parser.set_game_type(game_type)

    def parse(self):
        self._generating_object_parser.run_parsers()
        return self._generating_object_parser.get_result()


def main():
    adapter = ParserAdapter()
    main_frame = MainFrame(adapter)
    main_frame.draw()


if __name__ == '__main__':
    main()
