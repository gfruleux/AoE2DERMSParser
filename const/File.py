import os

FILE_OPTION_GEN = dict(defaultextension=".inc", title="Select AoE2DE GeneratingObjects.inc file",
                       initialdir="%s/Steam/steamapps/common/AoE2DE/resources/_common/drs/gamedata_x2" %
                                  os.environ.get("PROGRAMFILES(X86)"),
                       filetypes=[('Generating Objects', "*.inc"), ("All Files", "*.*")])

FILE_OPTION_RMS = dict(defaultextension=".rms", title="Select AoE2DE RMS Map files", multiple=True,
                       initialdir="%s/Steam/steamapps/common/AoE2DE/resources/_common/drs/gamedata_x2" %
                                  os.environ.get("PROGRAMFILES(X86)"),
                       filetypes=[("RMS files", "*.rms"), ("RMS2 files", "*.rms2"), ("All files", "*.*")])
