/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Power key press callback of the Xiaomi display driver
 */
#ifndef _LINUX_INPUT_MI_PWRKEY_H
#define _LINUX_INPUT_MI_PWRKEY_H

typedef int (*mi_display_pwrkey_callback)(int);

void mi_display_pwrkey_callback_set(mi_display_pwrkey_callback cb);

#endif /* _LINUX_INPUT_MI_PWRKEY_H */
