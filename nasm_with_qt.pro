QT += core gui widgets

TARGET = nasm_with_qt
TEMPLATE = app
CONFIG += c++17

SOURCES += main.cpp mainwindow.cpp customdialog.cpp
HEADERS += mainwindow.h customdialog.h

QMAKE_EXTRA_COMPILERS += nasm
NASMEXTRAFLAGS = -f elf64 -g -F dwarf
OTHER_FILES += $$NASM_SOURCES
nasm.output = ${QMAKE_FILE_BASE}.o
nasm.commands = nasm $$NASMEXTRAFLAGS -o ${QMAKE_FILE_BASE}.o ${QMAKE_FILE_NAME}
nasm.input = NASM_SOURCES

unix {
NASM_SOURCES += assembly_unix.asm
}

win32 {
NASM_SOURCES += assembly_win32.asm
}
