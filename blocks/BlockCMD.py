class BlockCMD:
    def __init__(self, precedence):
        self.contentList = []
        self.precedence = precedence

    def display(self, cond_list):
        out = ""
        for elt in self.contentList:
            out += elt.display(cond_list)
        return out
