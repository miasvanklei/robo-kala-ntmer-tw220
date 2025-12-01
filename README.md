# Robo & Kala (Ntmer TW220), a 8cx Gen 3 Tablet

This repo contains the efforts in supporting Linux on the Robo & Kala.

## Feature Support
| Feature             | Status                                                    |
|---------------------|-----------------------------------------------------------|
| Audio               | works                                                     |
| - Mic               | works                                                     |
| - Speakers          | works                                                     |
| Backlight           | does not work, see [display](#display)                    |
| Bluetooth           | works [bluetooth](#bluetooth)                             |
| Camera              | see [camera](#camera) for more details                    |
| - ov13b10           | driver exists, but has no OF support                      |
| - ov9234            | black and white version of OV9734                         |
| - gc5035            | driver exists on mailig list                              |
| Charge              | works                                                     |
| Display             | does not work, see [display](#display)                    |
| GPU                 | works                                                     |
| Keyboard & Touchpad | connected over usb                                        |
| Lid                 | works                                                     |
| Pcie NVMe           | works                                                     |
| Power & Volume keys | works                                                     |
| Sensors             | not verified, slpi loads                                  |
| Suspend             | works, but battery drains                                 |
| Touchscreen         | works                                                     |
| USB                 | works                                                     |
| - DP Alt Mode       | does not work, see [altmode](#altmode)                    |
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

The Robo & kala has 2 usb-c connectors, and 1 usb connector via pogo pins (keyboard & touchpad).
See [acpi layout](./usb/acpi-layout) for the ACPI structure all usb devices. The layout difers from the X13s:
 - X13s has 2 ports on usb0 and usb1 connected under a RHUB, the Robo & Kala only one.
 - The Robo & kala has a usb4 router defined in the ACPI (UBF0) with 2 ports, which is missing om the X13s.
 - The PHYC method on usb0 and usb1 contains data, which is missing on the X13s.

I don't know if these differences affect the working of the DP Altmode. When connecting an external display through usb-c the following is logged:
```
[ 1363.960484] msm_dpu ae01000.display-controller: [drm:msm_dp_bridge_hpd_notify] type=10 link hpd_link_status=0x0, link_ready=0, status=2
[ 1363.960511] msm_dpu ae01000.display-controller: [drm:msm_dp_hpd_unplug_handle] Before, type=10 sink_count=0, link_ready=0
[ 1363.960625] msm_dpu ae01000.display-controller: [drm:msm_dp_bridge_hpd_notify] type=10 link hpd_link_status=0x0, link_ready=0, status=2
[ 1363.960636] msm_dpu ae01000.display-controller: [drm:msm_dp_hpd_unplug_handle] Before, type=10 sink_count=0, link_ready=0
[ 1363.960649] msm_dpu ae01000.display-controller: [drm:msm_dp_bridge_hpd_notify] type=10 link hpd_link_status=0x0, link_ready=0, status=2
[ 1363.960657] msm_dpu ae01000.display-controller: [drm:msm_dp_hpd_unplug_handle] Before, type=10 sink_count=0, link_ready=0
[ 1363.960676] msm_dpu ae01000.display-controller: [drm] Cannot find any crtc or sizes
[ 1365.102416] msm_dpu ae01000.display-controller: [drm:msm_dp_bridge_hpd_notify] type=10 link hpd_link_status=0x0, link_ready=0, status=1
[ 1365.102445] msm_dpu ae01000.display-controller: [drm:msm_dp_hpd_plug_handle] Before, type=10 sink_count=0, link_ready=0
[ 1365.102684] msm_dpu ae01000.display-controller: [drm:msm_dp_pm_runtime_resume] type=10 core_init=0 phy_init=1
[ 1365.102704] [drm:msm_dp_ctrl_core_clk_enable] enable core clocks 
[ 1365.102718] [drm:msm_dp_ctrl_core_clk_enable] stream_clks:off link_clks:off core_clks:on
[ 1365.103858] msm_dpu ae01000.display-controller: [drm:msm_dp_hpd_plug_handle] type=10 core_init=1 phy_init=1
[ 1367.025573] usb 5-1: new high-speed USB device number 11 using xhci-hcd
[ 1373.321042] msm_dpu ae01000.display-controller: [drm:drm_dp_dpcd_probe] dpu_dp_aux: 0x00102 AUX -> (ret=-110)
[ 1373.321077] msm_dpu ae01000.display-controller: [drm:msm_dp_pm_runtime_suspend] type=10 core_init=1 phy_init=1
```
The following log statement
```
dpu_dp_aux: 0x00102 AUX -> (ret=-110)
```
is of particular interest. It seem's as if the mux does not want to switch. I have no idea yet on how to fix or debug this

## Camera
TODO
## Wifi & Bluetooth
TODO
## EL2
TODO
## Other Issues
