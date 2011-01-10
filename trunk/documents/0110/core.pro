TEMPLATE = app

TARGET = core

DEPENDPATH += .

INCLUDEPATH += .

QT += declarative

SOURCES +=

sources.files = \
        pictures \
	view.qml\
	QuitButton.qml \
	Snow.qml \
	Snowflake.qml

INSTALLS += sources target
