from blocks.BlockCMD import *


class BlockCond(BlockCMD):
    def __init__(self, condition, precedence):
        BlockCMD.__init__(self, precedence)
        self.condition = condition
        self.counterPart = None

    def display(self, cond_list):
        out = ""
        if self.condition in cond_list:
            for elt in self.contentList:
                out += elt.display(cond_list)
        elif self.counterPart is not None:
            out = self.counterPart.display(cond_list)
        return out
