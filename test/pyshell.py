#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from __future__ import print_function
import os
import cmd
import sys




class PyShell(cmd.Cmd):
    def __init__(self):
        if sys.version_info.major == 2:
            cmd.Cmd.__init__(self)
        else:
            super(self.__class__, self).__init__()

        if os.uname()[0] == "Linux":
            self.pwd = '/'
        elif os.uname()[0] == "Windows":
            self.pwd = 'C:\\'
        else:
            print ("Error: your OS doesn't support")
            exit(1)

        os.chdir(self.pwd)
        self.prompt = "%s " % self.pwd


    def do_cd(self, args):
        if args:
            if os.path.exists(args[0]):
                self.pwd = args[0]
                os.chdir(self.pwd)

    def precmd(self, line):
        self.prompt = "%s " % self.pwd
        return ""


    def postcmd(self, stop, line):
        self.prompt = "%s " % self.pwd
        return ""



if __name__ == "__main__":
    try:
        PyShell().cmdloop()
    except KeyboardInterrupt:
        sys.stdout.write("\n")
        exit()
