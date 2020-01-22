class BlockLine:
    def __init__(self, line):
        self.line = line

    def display(self, cond_list):
        formatted = ""
        if self.line.startswith("{"):
            formatted = self.line + "\n"
        elif self.line.startswith("}"):
            formatted = self.line + "\n\n"
        else:
            formatted = self.line + "\n"
        return formatted

    def __str__(self):
        return self.line
