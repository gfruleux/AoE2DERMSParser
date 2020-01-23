class ParserMapConstFiles:
    def __init__(self, path_list: list, const_list: list):
        self.path_list = path_list
        self._table_const = {}
        for file_path in self.path_list:
            file_path_split = file_path.split("/")
            file_name = file_path_split[len(file_path_split) - 1]
            # ### Process Const file
            self._table_const[file_name] = []
            with open(file_path, "r") as fp_read:
                for line in fp_read:
                    line = line.strip()
                    if line.startswith("#define"):
                        self._table_const[file_name].append(line.split(" ")[1])
            # ### Append const_list
            self._table_const[file_name] += const_list

    def get_result(self):
        return self._table_const
