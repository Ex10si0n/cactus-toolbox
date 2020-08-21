#! /usr/bin/env python3

import os, sys

# Preference Settings Starts

# Preference Settings Ends

usage = \
'''
\033[0;36mWelcome to 🌵cactus-ToolBox by Ex10si0n.\033[0m
Usage:
  c <commands> [words]

Commands:
  [Browsing]
      s [text]              Search from Google. \033[0;36m Searching by googler\033[0m
      w                     Display local Weather.
      w [city name]         Display Location Weather. \033[0;36m Weather by wttr.in\033[0m
      ip                    Get Host/Proxy IP address.
      f                     Quick Ranger File Manager. \033[0;36m Ranger\033[0m

  [macOS Features]
      a [app name]          Open Applications. \033[0;36m From Application Folder\033[0m
      s                     Call Siri.

  [Utilities]
      c txt [file name]     Convert .docx to .txt

  [Quick Commands]
      g                     Git Status
      g c                   Git Quick Commit
      g p                   Git Quick Pull
      p                     Quick ipython \033[0;36m Quick Calculator\033[0m
      sh f                  Quick Edit fish config \033[0;36m at ~/.config/fish/config.fish\033[0m
      sh z                  Quick Edit zsh config \033[0;36m at ~/.zshrc\033[0m
'''
class ToolBox:

    def commands(args):

        if len(args) == 1:
            print(usage)

        # Google Entry
        if len(args) == 3 and args[1] == 's':
            ToolBox.google(args[2])

        # Applications Entry
        if len(args) == 3 and args[1] == 'a':
            ToolBox.application(args[2])

        # Siri Entry
        if len(args) == 2 and args[1] == 's':
            os.system('open -a Siri.app')

        # IP Entry
        if len(args) == 2 and args[1] == 'ip':
            os.system('curl cip.cc')

        # Weather Entry
        if len(args) == 2 and args[1] == 'w':
            os.system('curl wttr.in')
            os.system('curl v2d.wttr.in')

        if len(args) == 3 and args[1] == 'w':
            os.system('curl wttr.in/'+args[2])
            os.system('curl v2d.wttr.in/'+args[2])

        # Git Entry
        if len(args) == 2 and args[1] == 'g':
            os.system('git status')
        if len(args) == 3 and args[1] == 'g':
            if args[2] == 'c':
                os.system('git add .')
                os.system('git commit -m "Update"')
                os.system('git push')
            if args[2] == 'p':
                os.system('git pull')

        # iPython Entry
        if len(args) == 2 and args[1] == 'p':
            os.system('ipython')

        # Convert Entry
        if len(args) == 4 and args[1] == 'c':
            if args[2] == 'txt':
                os.system('textutil -convert txt '+args[3])

        # Ranger Entry
        if len(args) == 2 and args[1] == 'f':
            os.system('ranger')

        # fish Entry
        if len(args) == 3 and args[1] == 'sh':
            if args[2] == 'f':
                os.system('vim ~/.config/fish/config.fish')

        # zsh Entry
        if len(args) == 3 and args[1] == 'sh':
            if args[2] == 'z':
                os.system('vim ~/.zshrc')

    def application(name):
        os.system('open -a '+name+'.app')

    def google(text):
        os.system('googler '+text)



def cprint(color, msg):
    print("\033[0;"+str(color)+"m%s\033[0m" % msg)

if __name__ == '__main__':
    a = sys.argv
    ToolBox.commands(a)

