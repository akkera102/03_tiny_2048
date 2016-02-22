Tiny 2048 for Arduboy

■転送方法
windows版「Arduino IDE」の付属ツールを使って転送します。

このフォルダにある「test.bat」をテキストエディタで開いて
VAL1～VAL4（2行目～5行目）を環境に合わせて修正してください。

ArduboyをUSB接続して「test.bat」を実行すれば転送されます。


■ルール
2048のパネル合成は加算していけど、こちらは連番になります。
2 + 2 -> 4ではなく3。
4 + 4 -> 8ではなく5。

ゴールは10にすることです。


■遊び方
方向ボタン　　移動
Ａ＋Ｂボタン　リセット


■開発環境
・Windows 8.1 pro
・Arduino IDE 1.6.7
・Arduino IDE 1.0.6(make.exeのみ使用。最新に入っていない為)
・Visual Studio 2015 C#
・Python 2.7 + pil


■履歴
v1.00 2016/02/20    とりあえず完成


AVR Memory Usage
----------------
Device: atmega32u4

Program:   15862 bytes (48.4% Full)
(.text + .data + .bootloader)

Data:       2121 bytes (82.9% Full)
(.data + .bss + .noinit)
