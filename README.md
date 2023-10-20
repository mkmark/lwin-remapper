# left windows key remapper

In short, this program maps the single press of `LWin` to `LWin + F23` while preserving the key as a modifier.

This is a workaround to address https://github.com/microsoft/PowerToys/issues/5571.

When `Win` is pressed alone, the start menu is activated. By remapping only sequential `LWin` press and release events to `LWin + F23`, one can suppress the action and use the key for other purposes, while preserving the key as a modifier. If there is no actions allocated to this combination, this is as good as supressing the single press of the key.

The Python file shows a pilot test using the keyboard lib (mapping `LWin` to `LWin + F12`). Due to unknown reasons, this approach may have a chance to miss (fail to catch the keyboard events) under certain circumstances.

The C++ approach does not have this issue.

## notes on using PowerToys Run

To change the activation key combination of PowerToys Run, one can use for example `F23` by editing `~\AppData\Local\Microsoft\PowerToys\PowerToys Run\settings.json`

```json
    "open_powerlauncher": {
      "win": true,
      "ctrl": false,
      "alt": false,
      "shift": false,
      "code": 134,
      "key": ""
    },
```
where code 134 is `F23`, see https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes.
