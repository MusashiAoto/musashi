#fixed version
#
#Credit: http://urin.github.io/posts/2013/simple-makefile-for-clang/
#Title: シンプルで応用の効くmakefileとその解説
#
#このmakefileのいいところ
#
#・コンパイル対象となるソースファイルをワイルドカードで指定できる。
#・ヘッダファイル、ライブラリ、オブジェクトファイルなどコンパイル、リンクに
#  関連するどのファイルが外部で変更されていてもきちんと差分コンパイルされる。
#
#使用方法
#
#・make
#  基本的にはmakeするだけで依存関係を考慮して差分コンパイルされる。
#  ソースファイルはもちろん、ヘッダファイル、ライブラリなどが
#  更新されている場合も自動的に検出して差分コンパイルされる。
#
#・make all
#  強制的に全ソースをコンパイルしたい場合はmake allする。
#  このコマンドは全ての中間ファイル（オブジェクトファイル、依存関係ファイル）と
#  実行ファイルを削除してから全ソースをコンパイルする。
#
#・make clean
#  全ての中間ファイル（オブジェクトファイル、依存関係ファイル）と
#  実行ファイルを削除する。
#
#初期設定状態のmakefile
#
#  下記のようなディレクトリツリーで初期設定のmakefileを用いてmakeを実行した場合、
#  以下の矢印(<-)ようにファイルが生成される。
#  同一のディレクトリに存在する全てのcppファイルがコンパイル（及びリンク）対象となる。
#
#  example
#  |-- makefile
#  |-- bin
#  |   `-- example		<- (TARGET) 実行ファイル
#  |-- include
#  |   `-- example.h
#  |-- obj						<- (OBJDIR) 中間ファイル生成先ディレクトリ
#  |   |-- example.d	<- (DEPENDS) 依存関係ファイル
#  |   `-- example.o	<- (OBJECTS) オブジェクトファイル
#  `-- source
#      `-- example.cpp
#
#解説
#
#・コンパイラの指定 (COMPILER)
#  コンパイラはCOMPILERの値を用いる。初期値はg++。
#  C言語のみの場合はgccに変更しても良いが基本的にはg++で問題ない。
#
#・コンパイルオプション (CFLAGS)
#  コンパイルオプションとしてCFLAGSの値を用いる。
#  -Dオプションによる#defineの追加、最適化オプション、
#  コードカバレッジ用の-coverageなどを用いる場合はここに記述する。
#
#  以下は初期値の解説。
#  -Wall -Wextra -Winit-self -Wno-missing-field-initializers
#    -Wall : コンパイルワーニングのレベルを最大にする。
#    -Wextra : 歴史的理由により-Wallを使用でも抑制される警告を抑制しない。
#              つまり可能な限り全ての警告を出す。
#    -W*（それ以外） : 詳しくは
#                      Warning Options - Using the GNU Compiler Collection (GCC)
#                      を参照されたし。
#  -g
#    デバッグオプション。
#    gdbでのデバッグを可能にする。
#  -MMD -MP
#    ソースファイルの依存関係を中間ファイルに出力する。
#    依存関係ファイルはソースファイル名の拡張子を.dに変更したものとなり、
#    OBJDIRで指定したディレクトリに生成される。
#    この依存関係ファイルはmakefile最後のinclude文にてインクルードされることで
#    依存しているヘッダファイル等が変更された場合に自動的に再コンパイルされるようになる。
#
#・リンクオプション (LDFLAGS)
#  リンクオプションとしてLDFLAGSの値を用いる。初期値は空。
#  動的ライブラリをリンクする-lオプションを用いる場合はここに記述する。
#  パスの通っていない動的ライブラリをリンクするなら
#  ここにそのファイル名(*.soみたいな)を書いても良い。
#
#・ライブラリの指定 (LIBS)
#  静的リンクするライブラリとしてLIBSの値を用いる。初期値は空。
#  静的ライブラリ（*.a）を用いる場合、空白区切りでファイル名を記述する。
#  ここで指定したライブラリが更新された場合、makeは再コンパイルが必要だと認識する。
#
#・インクルードパスの指定 (INCLUDE)
#  インクルードパスとしてINCLUDEの値を用いる。初期値は-I./include。
#  ソースファイル中の#includeファイル検索パスに加えるパスを-Iオプションにて指定する。
#  -Iオプションとディレクトリ名の間に空白を書くことはできない。
#  複数ディレクトリを指定したい場合は-Iオプションを空白区切りで複数指定する。
#
#・実行ファイルの指定 (TARGET)
#  実行ファイル名としてTARGETの値を用いる。
#  以下は初期値 ./bin/$(shell basename `readlink -f .`) の解説。
#  実行ファイルの生成先のディレクトリは./bin。
#  生成される実行ファイル名は $(shell basename `readlink -f .`) である。
#  これはmakefileの存在するディレクトリの名前。
#
#・中間ファイル生成先ディレクトリの指定 (OBJDIR)
#  中間ファイル生成先ディレクトリとしてOBJDIRの値を用いる。初期値は./obj。
#  このフォルダにオブジェクトファイル(*.o)や依存関係ファイル(*.d)が生成される。
#
#・ソースファイルの指定 (SOURCES)
#  コンパイル対象となるソースファイルとしてSOURCESの値を用いる。
#  初期値は$(wildcard $(SRCDIR)/*.cpp)。
#  SRCDIRに存在する拡張子cppのファイル全てをコンパイル対象とすることを意味する。
#  別の拡張子(.cなど)に変更したい場合は、makefile内のcppを全て変更する。
#
#・オブジェクトファイルの指定 (OBJECTS)
#  オブジェクトファイルとしてOBJECTSの値を用いる。
#  以下は初期値 $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.cpp=.o)))の解説。
#  オブジェクトファイルの生成先ディレクトリはOBJDIR。
#  オブジェクトファイル名はソースファイル(SOURCES)の拡張子を.oに置換したもの。
#  OBJDIRが空の場合はmakefileと同一のディレクトリに生成される。
#
#・依存関係ファイルの指定 (DEPENDS)
#  依存関係ファイルとしてDEPENDSの値を用いる。
#  初期値$(OBJECTS:.o=.d)はオブジェクトファイルの拡張子を.dに置換したもの。

COMPILER = gcc
CFLAGS = -g -MMD -MP -Wall -Wextra -Winit-self -Wno-missing-field-initializers
ifeq "$(shell getconf LONG_BIT)" "64"
	LDFLAGS =
else
	LDFLAGS =
endif
OS := $(shell uname)
ifeq ($(OS),Darwin)
	LIBS = -lcreateoi
else
	LIBS = -lm -lncurses -lcreateoi -lpthread
endif
#CVFLAGS = $(shell pkg-config --libs opencv)  $(shell pkg-config --cflags opencv)
TGTDIR = ./$(NAME)
INCLUDE = /usr/local/include
INCDIR = -I$(TGTDIR)/inc
TARGET = $(TGTDIR)/bin/$(NAME)
SRCDIR = $(TGTDIR)/src
ifeq "$(strip $(SRCDIR))" ""
	SRCDIR = $(TGTDIR)
endif
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJDIR = $(TGTDIR)/obj
ifeq "$(strip $(OBJDIR))" ""
	OBJDIR = $(TGTDIR)
endif
OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:.c=.o)))
DEPENDS = $(OBJECTS:.o=.d)

DIRNAME = $(shell ls | grep -x $(NAME))

$(TARGET): $(OBJECTS) $(LIBS)
	@if [ "$(DIRNAME)" = "wander" ]; then echo "$(COMPILER) $(CFLAGS) $^ $(CVFLAGS) $(LDFLAGS) -o $@"; $(COMPILER) $(CFLAGS) $^ $(CVFLAGS) $(LDFLAGS) -o $@;\
	elif [ "$(DIRNAME)" = "tracker" ]; then echo "$(COMPILER) $(CFLAGS) $^ $(CVFLAGS) $(LDFLAGS) -o $@"; $(COMPILER) $(CFLAGS) $^ $(CVFLAGS) $(LDFLAGS) -o $@;\
	elif [ -n "$(DIRNAME)" ]; then echo "$(COMPILER) $(CFLAGS) $^ $(LDFLAGS) -o $@"; $(COMPILER) $(CFLAGS) $^ $(LDFLAGS) -o $@;\
	else echo "ERROR: not exists $(NAME)";\
	fi

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCDIR) -o $@ -c $<

all: clean $(TARGET)

clean:
	@if [ -n "$(DIRNAME)" ]; then echo "rm -f $(OBJDIR)/*.o $(OBJDIR)/*.d $(TARGET)"; rm -f $(OBJDIR)/*.o $(OBJDIR)/*.d $(TARGET);\
	else echo "ERROR: not exists $(NAME)";\
	fi

-include $(DEPENDS)
