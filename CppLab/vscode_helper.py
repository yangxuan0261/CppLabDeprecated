#!/usr/bin/env python
#-*- coding: utf-8 -*-

################################################
# windows 环境需要把 git.exe 的路径加入环境变量，如 F:\Git\bin
################################################

import os
import sys
from optparse import OptionParser

SelfPath = sys.path[0]

def GetAllCppFile(projPath):
    print("projPath:%s", projPath)
    cppList = []
    for root, dirs, files in os.walk(projPath):
        for name in files:
            if (os.path.splitext(name)[1] == '.cpp'):
                fullPath = os.path.join(root, name).replace("\\", "/")
                fullPath = fullPath.replace(projPath + "/", "")
                # print("name:%s", name)
                # print("fullPath:%s", fullPath)
                cppList.append(fullPath)

    retStr = ""
    for file in cppList:
        retStr = retStr + file + " "

    # print("retStr:%s", retStr)
    return retStr

def Build(projPath, outputFile):
    os.chdir(SelfPath)
    cppStr = GetAllCppFile(projPath)
    cmd = "g++ -g %s -o %s" % (cppStr, outputFile)
    os.system(cmd)
    pass

def main():
    parser = OptionParser()
    parser.add_option("-d", "--dir", action="store", dest="projPath", help=u'cpp目录', type="string", default="nodir")
    parser.add_option("-o", "--output", action="store", dest="outputFile", help=u'导出可执行程序文件', type="string", default="nofile")
    (options, args) = parser.parse_args()

    if (options.projPath == "nodir" or options.outputFile == "nofile"):
        print(u"参数错误 \n projPath%s\n outputFile:%s\n" % (options.projPath, options.outputFile))
        return

    print(u"参数ok \n projPath%s\n outputFile:%s\n" % (options.projPath, options.outputFile))
    Build(options.projPath.replace("\\", "/"), options.outputFile.replace("\\", "/"))

if __name__ == '__main__':
    main()
    sys.exit(0)
