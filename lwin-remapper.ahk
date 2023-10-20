#Requires AutoHotkey v2.0-a
; #NoTrayIcon

;; this method has such a problem that any win combination will trigger Lwin+F23 first
~LWin::F23

;; this method has such a problem that you will have to press combinations (like Win + tab) really fast for it to work
; ~LWin::{
;   Send "{Blind}{F24}" 
; }
  
;; this method has such a problem that Win key is forced to be only a prefix, so that shortcut where Win is used as a modifier but not a prefix, like Ctrl + Win + Left does not work anymore
; #NoEnv
; SendMode Input
; ~LWin & F1::return  ; Make LWin a prefix key (https://www.autohotkey.com/docs/v2/Hotkeys.htm#prefix)
; LWin::#F23
