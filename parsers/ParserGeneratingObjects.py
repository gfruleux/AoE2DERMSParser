from blocks.BlockElse import BlockElse
from blocks.BlockElseIf import BlockElseIf
from blocks.BlockIf import BlockIf
from blocks.BlockLine import BlockLine


class ParserGeneratingObjects:
    def __init__(self, path):
        self.path = path
        self._gen_object = []
        ptr_table = self._gen_object
        ptr_block = None
        com_skip = False
        with open(self.path, "r") as fp:
            for line in fp:
                line = line.strip()
                block = None
                update_block = False

                # ### Skippable lines
                if line.startswith("#") or len(line) == 0:
                    # single com
                    continue
                elif line.find("/*") != -1 and line.find("*/") != -1:
                    # inline com /* */
                    if line.startswith("/*"):
                        continue
                elif line.startswith("/*"):
                    # multi-line com start /*
                    com_skip = True
                    continue
                elif line.endswith("*/"):
                    # multi-line com end */
                    com_skip = False
                    continue
                elif com_skip:
                    continue

                if line.startswith("if "):
                    # ### IF ###
                    cond = line.split(" ")[1].strip()
                    block = BlockIf(cond, ptr_block)
                    ptr_table.append(block)
                    update_block = True
                elif line.startswith("elseif "):
                    # ### ELSEIF ###
                    cond = line.split(" ")[1].strip()
                    block = BlockElseIf(cond, ptr_block.precedence)
                    ptr_block.counterPart = block
                    update_block = True
                elif line.startswith("else"):
                    # ### ELSE ###
                    block = BlockElse(ptr_block.precedence)
                    ptr_block.counterPart = block
                    update_block = True
                elif line.startswith("endif"):
                    # ### ENDIF ###
                    if ptr_block.precedence is None:
                        ptr_block = None
                        ptr_table = self._gen_object
                    else:
                        ptr_block = ptr_block.precedence
                        ptr_table = ptr_block.contentList
                else:
                    # ### CONTENT ###
                    block = BlockLine(line)
                    ptr_table.append(block)

                if update_block:
                    ptr_block = block
                    ptr_table = block.contentList

    def get_result(self):
        return self._gen_object
