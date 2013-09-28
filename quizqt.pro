HEADERS = quizbutton.hh \
          quizcategoryselection.hh \
          quizdialog.hh \
          quizerrormessagebox.hh \
          quizplayerbutton.hh \
          quizquestiondialog.hh \
          quizsubcategoryselection.hh \
          quizwindow.hh

SOURCES = quizbutton.cpp \
          quizcategoryselection.cpp \
          quizdialog.cpp \
          quizerrormessagebox.cpp \
          quizplayerbutton.cpp \
          quizquestiondialog.cpp \
          quizsubcategoryselection.cpp \
          quizwindow.cpp \
          main.cpp

TEMPLATE = app
LIBS += -L./ -lquizqtbase
INCLUDEPATH += ./libquizqt
DESTDIR = ./
