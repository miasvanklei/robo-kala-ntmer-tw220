# Robo & Kala (Ntmer TW220), a 8cx Gen 3 Tablet

This repo contains the efforts in supporting Linux on the Robo & Kala.

## Feature Support
| Feature             | Status                                                    |
| Audio               | works                                                     |
| - Mic               | works                                                     |
| - Speakers          | works                                                     |
| Backlight           | does not work, see [#display]                             |
| Bluetooth           | works [#bluetooth]                                        |
| Camera              | see [#camera] for more details                            |
| - ov13b10           | driver exists, but has no OF support                      |
| - ov9234            | black and white version of OV9734                         |
| - gc5035            | driver exists on mailig list                              |
| Charge              | works                                                     |
| Display             | does not work, see [#display]                             |
| GPU                 | works                                                     |
| Keyboard & Touchpad | connected over usb                                        |
| Lid                 | works                                                     |
| Pcie NVMe           | works                                                     |
| Power & Volume keys | works                                                     |
| Sensors             | not verified, slpi loads                                  |
| Suspend             | works, but battery drains                                 |
| Touchscreen         | works                                                     |
| USB                 | works                                                     |
| - DP Alt Mode       | does not work, see [#altmode]                             |
| Video Acceleration  | not verified                                              |
| Wi-Fi               | works                                                     |
| EL2                 | secure boot?                                              |
## Secure boot
TODO
## Audio
TODO
## Internal Display
TODO
## Altmode

Altmode does not work. The following is seen in kernel log:
```
[ 1084.525702] msm_dpu ae01000.display-controller: [drm:drm_sysfs_connector_hotplug_event] [CONNECTOR:34:DP-1] generating connector hotplug event
[ 1084.525792] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] 
[ 1084.525807] [drm:drm_mode_object_get] OBJ ID: 34 (2)
[ 1084.525822] msm_dpu ae01000.display-controller: [drm:drm_helper_probe_single_connector_modes] [CONNECTOR:34:DP-1]
[ 1084.526457] msm_dpu ae01000.display-controller: [drm:drm_helper_probe_single_connector_modes] [CONNECTOR:34:DP-1] disconnected
[ 1084.526475] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] No connectors reported connected with modes
[ 1084.526487] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] [CONNECTOR:34:DP-1] enabled? no
[ 1084.526505] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] Not using firmware configuration
[ 1084.526518] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] picking CRTCs for 16383x16383 config
[ 1084.526532] [drm:drm_mode_object_put] OBJ ID: 34 (2)
[ 1084.526542] msm_dpu ae01000.display-controller: [drm:__drm_fb_helper_initial_config_and_unlock] test CRTC 0 primary plane
[ 1084.526559] msm_dpu ae01000.display-controller: [drm] Cannot find any crtc or sizes
[ 1084.526563] msm_dpu ae01000.display-controller: [drm:drm_client_dev_hotplug] fbdev: ret=0
[ 1085.708561] msm_dpu ae01000.display-controller: [drm:drm_sysfs_connector_hotplug_event] [CONNECTOR:34:DP-1] generating connector hotplug event
[ 1085.708653] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] 
[ 1085.708668] [drm:drm_mode_object_get] OBJ ID: 34 (2)
[ 1085.708684] msm_dpu ae01000.display-controller: [drm:drm_helper_probe_single_connector_modes] [CONNECTOR:34:DP-1]
[ 1085.708699] msm_dpu ae01000.display-controller: [drm:drm_helper_probe_single_connector_modes] [CONNECTOR:34:DP-1] status updated from connected to disconnected
[ 1085.708715] msm_dpu ae01000.display-controller: [drm:drm_helper_probe_single_connector_modes] [CONNECTOR:34:DP-1] disconnected
[ 1085.708730] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] No connectors reported connected with modes
[ 1085.708741] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] [CONNECTOR:34:DP-1] enabled? no
[ 1085.708760] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] Not using firmware configuration
[ 1085.708773] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] picking CRTCs for 16383x16383 config
[ 1085.708787] [drm:drm_mode_object_put] OBJ ID: 34 (2)
[ 1085.708797] msm_dpu ae01000.display-controller: [drm:__drm_fb_helper_initial_config_and_unlock] test CRTC 0 primary plane
[ 1085.708813] msm_dpu ae01000.display-controller: [drm] Cannot find any crtc or sizes
[ 1085.708818] msm_dpu ae01000.display-controller: [drm:drm_client_dev_hotplug] fbdev: ret=0
[ 1085.708857] msm_dpu ae01000.display-controller: [drm:drm_sysfs_hotplug_event] generating hotplug event
[ 1085.708878] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] 
[ 1085.708888] [drm:drm_mode_object_get] OBJ ID: 34 (2)
[ 1085.708897] msm_dpu ae01000.display-controller: [drm:drm_helper_probe_single_connector_modes] [CONNECTOR:34:DP-1]
[ 1085.708907] msm_dpu ae01000.display-controller: [drm:drm_helper_probe_single_connector_modes] [CONNECTOR:34:DP-1] disconnected
[ 1085.708916] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] No connectors reported connected with modes
[ 1085.708927] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] [CONNECTOR:34:DP-1] enabled? no
[ 1085.708939] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] Not using firmware configuration
[ 1085.708958] msm_dpu ae01000.display-controller: [drm:drm_client_modeset_probe] picking CRTCs for 16383x16383 config
[ 1085.708970] [drm:drm_mode_object_put] OBJ ID: 34 (2)
[ 1085.708978] msm_dpu ae01000.display-controller: [drm:__drm_fb_helper_initial_config_and_unlock] test CRTC 0 primary plane
[ 1085.708989] msm_dpu ae01000.display-controller: [drm] Cannot find any crtc or sizes
[ 1085.708993] msm_dpu ae01000.display-controller: [drm:drm_client_dev_hotplug] fbdev: ret=0
[ 1085.709110] [drm:mdss_runtime_resume] 
[ 1087.574637] usb 3-1: new high-speed USB device number 6 using xhci-hcd
[ 1093.903875] msm_dpu ae01000.display-controller: [drm:drm_dp_dpcd_access] dpu_dp_aux: Too many retries, giving up. First error: -110
[ 1093.905052] [drm:mdss_runtime_suspend] 
```

The following log statement
```
dpu_dp_aux: Too many retries, giving up. First error: -110
```
Could be an indication

In [.\usb\acpi-layout] is documented how the ACPI structure is of all usb devices.

## Camera
TODO
## Wifi & Bluetooth
TODO
## EL2
TODO
## Other Issues
