// SPDX-License-Identifier: GPL-2.0-only
/*
 * Generated with linux-mdss-dsi-panel-driver-generator, translated from panel.xml
 * Copyright (c) 2025, Mias van Klei <miasvanklei@outlook.com>
 */

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct rm69380_n1 {
        struct drm_panel panel;
        struct mipi_dsi_device *dsi;
        struct regulator *supply;
        struct gpio_desc *reset_gpio;
        struct gpio_desc *avdd_gpio;
        struct gpio_desc *avee_gpio;
        struct gpio_desc *blreg_gpio;
        struct gpio_desc *blen_gpio;
};

static inline struct rm69380_n1 *to_rm69380_n1(struct drm_panel *panel)
{
        return container_of(panel, struct rm69380_n1, panel);
}

static void rm69380_n1_reset(struct rm69380_n1 *ctx)
{
        gpiod_set_value_cansleep(ctx->reset_gpio, 0);
        usleep_range(8000, 9000);
        gpiod_set_value_cansleep(ctx->reset_gpio, 1);
        usleep_range(8000, 9000);
        gpiod_set_value_cansleep(ctx->reset_gpio, 0);
}

static int rm69380_n1_on(struct rm69380_n1 *ctx)
{
        struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

        ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xd1);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd3, 0x00);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd0, 0x00);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2, 0x00);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd4, 0x00);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb4, 0x01);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xa1);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb1, 0x04);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcd, 0x6b);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xce, 0xbb);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x40);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb3, 0x08);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x26);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x32, 0x07);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xfd);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x80, 0x04);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x83, 0x00);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xd0);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7e, 0x80);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xd2);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x23, 0x56);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xa1);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb3, 0x3f);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe3, 0x03);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3, 0x83);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc4, 0xff);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x5f);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xfd);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xee, 0x00);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xef, 0x00);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0xa0);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_VSYNC_TIMING, 0x3c);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x00);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
                                     0x28);
        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2, 0x08);
        mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
        mipi_dsi_dcs_set_display_brightness_multi(&dsi_ctx, 0x00ff);
        mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
        mipi_dsi_msleep(&dsi_ctx, 112);
        mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
        mipi_dsi_msleep(&dsi_ctx, 48);

        return dsi_ctx.accum_err;
}

static int rm69380_n1_off(struct rm69380_n1 *ctx)
{
        struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

        ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

        mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfe, 0x00);
        mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
        mipi_dsi_msleep(&dsi_ctx, 40);
        mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
        mipi_dsi_msleep(&dsi_ctx, 40);

        return dsi_ctx.accum_err;
}

static int rm69380_n1_prepare(struct drm_panel *panel)
{
        struct rm69380_n1 *ctx = to_rm69380_n1(panel);
        struct device *dev = &ctx->dsi->dev;
        int ret;

        ret = regulator_enable(ctx->supply);
        if (ret < 0) {
                dev_err(dev, "Failed to enable regulator: %d\n", ret);
                return ret;
        }

        // reset
        rm69380_n1_reset(ctx);

        //  panel
        gpiod_set_value_cansleep(ctx->avdd_gpio, 1)
	msleep(15);
        gpiod_set_value_cansleep(ctx->avee_gpio, 1);
	msleep(5);

        // backlight
        gpiod_set_value_cansleep(ctx->blen_gpio, 0);
	msleep(5);
        gpiod_set_value_cansleep(ctx->blreg_gpio, 0);
        msleep(5);

        ret = rm69380_n1_on(ctx);
        if (ret < 0) {
                dev_err(dev, "Failed to initialize panel: %d\n", ret);

                // backlight
                gpiod_set_value_cansleep(ctx->blen_gpio, 0);
	        msleep(5);
                gpiod_set_value_cansleep(ctx->blreg_gpio, 0);
                msleep(5);

                // panel
                gpiod_set_value_cansleep(ctx->avdd_gpio, 0);
		msleep(5);
                gpiod_set_value_cansleep(ctx->avee_gpio, 0);
		msleep(5);

                // reset
                gpiod_set_value_cansleep(ctx->reset_gpio, 1);

                regulator_disable(ctx->supply);

                return ret;
        }

        return 0;
}

static int rm69380_n1_unprepare(struct drm_panel *panel)
{
        struct rm69380_n1 *ctx = to_rm69380_n1(panel);
        struct device *dev = &ctx->dsi->dev;
        int ret;

        ret = rm69380_n1_off(ctx);
        if (ret < 0)
                dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

        // backlight
        gpiod_set_value_cansleep(ctx->blen_gpio, 0);
	msleep(5);
        gpiod_set_value_cansleep(ctx->blreg_gpio, 0);
        msleep(5);

        // panel
        gpiod_set_value_cansleep(ctx->avdd_gpio, 0);
	msleep(5);
        gpiod_set_value_cansleep(ctx->avee_gpio, 0);
	msleep(5);


        // reset
        gpiod_set_value_cansleep(ctx->reset_gpio, 1);

        regulator_disable(ctx->supply);

        return 0;
}

static const struct drm_display_mode rm69380_n1_mode = {
        .clock = (1280 + 32 + 12 + 38) * (1600 + 20 + 4 + 8) * 60 / 1000,
        .hdisplay = 1280,
        .hsync_start = 1280 + 32,
        .hsync_end = 1280 + 32 + 12,
        .htotal = 1280 + 32 + 12 + 38,
        .vdisplay = 1600,
        .vsync_start = 1600 + 20,
        .vsync_end = 1600 + 20 + 4,
        .vtotal = 1600 + 20 + 4 + 8,
        .width_mm = 0,
        .height_mm = 0,
        .type = DRM_MODE_TYPE_DRIVER,
};

static int rm69380_n1_get_modes(struct drm_panel *panel,
                                struct drm_connector *connector)
{
        return drm_connector_helper_get_modes_fixed(connector, &rm69380_n1_mode);
}

static const struct drm_panel_funcs rm69380_n1_panel_funcs = {
        .prepare = rm69380_n1_prepare,
        .unprepare = rm69380_n1_unprepare,
        .get_modes = rm69380_n1_get_modes,
};

static int rm69380_n1_bl_update_status(struct backlight_device *bl)
{
        struct mipi_dsi_device *dsi = bl_get_data(bl);
        struct rm69380_n1 *ctx = mipi_dsi_get_drvdata(dsi);
        u16 brightness = backlight_get_brightness(bl);
        int ret;

        gpiod_set_value_cansleep(ctx->blreg_gpio, !!brightness);

        dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

        ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
        if (ret < 0)
                return ret;

        dsi->mode_flags |= MIPI_DSI_MODE_LPM;

        return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int rm69380_n1_bl_get_brightness(struct backlight_device *bl)
{
        struct mipi_dsi_device *dsi = bl_get_data(bl);
        u16 brightness;
        int ret;

        dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

        ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
        if (ret < 0)
                return ret;

        dsi->mode_flags |= MIPI_DSI_MODE_LPM;

        return brightness;
}

static const struct backlight_ops rm69380_n1_bl_ops = {
        .update_status = rm69380_n1_bl_update_status,
        .get_brightness = rm69380_n1_bl_get_brightness,
};

static struct backlight_device *
rm69380_n1_create_backlight(struct mipi_dsi_device *dsi)
{
        struct device *dev = &dsi->dev;
        const struct backlight_properties props = {
                .type = BACKLIGHT_RAW,
                .brightness = 6000,
                .max_brightness = 6000,
        };

        return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
                                              &rm69380_n1_bl_ops, &props);
}

static int rm69380_n1_probe(struct mipi_dsi_device *dsi)
{
        struct device *dev = &dsi->dev;
        struct rm69380_n1 *ctx;
        int ret;

        ctx = devm_drm_panel_alloc(dev, struct rm69380_n1, panel,
                                   &rm69380_n1_panel_funcs,
                                   DRM_MODE_CONNECTOR_DSI);
        if (IS_ERR(ctx))
                return PTR_ERR(ctx);

        ctx->supply = devm_regulator_get(dev, "vddio");
        if (IS_ERR(ctx->supply))
                return dev_err_probe(dev, PTR_ERR(ctx->supply),
                                     "Failed to get vddio regulator\n");

        ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
        if (IS_ERR(ctx->reset_gpio))
                return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
                                     "Failed to get reset-gpios\n");

        ctx->avdd_gpio = devm_gpiod_get(dev, "avdd", GPIOD_OUT_LOW);
        if (IS_ERR(ctx->avdd_gpio))
                return dev_err_probe(dev, PTR_ERR(ctx->avdd_gpio),
                                     "Failed to get backlight-gpios\n");

        ctx->avee_gpio = devm_gpiod_get(dev, "avee", GPIOD_OUT_LOW);
        if (IS_ERR(ctx->avee_gpio))
                return dev_err_probe(dev, PTR_ERR(ctx->avee_gpio),
                                     "Failed to get backlight-gpios\n");

        ctx->blreg_gpio = devm_gpiod_get(dev, "blreg", GPIOD_OUT_LOW);
        if (IS_ERR(ctx->blreg_gpio))
                return dev_err_probe(dev, PTR_ERR(ctx->blreg_gpio),
                                     "Failed to get backlight-gpios\n");

        ctx->blen_gpio = devm_gpiod_get(dev, "blen", GPIOD_OUT_LOW);
        if (IS_ERR(ctx->blen_gpio))
                return dev_err_probe(dev, PTR_ERR(ctx->blen_gpio),
                                     "Failed to get backlight-gpios\n");

        ctx->dsi = dsi;
        mipi_dsi_set_drvdata(dsi, ctx);

        dsi->lanes = 4;
        dsi->format = MIPI_DSI_FMT_RGB888;
        dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_NO_EOT_PACKET |
                          MIPI_DSI_CLOCK_NON_CONTINUOUS;

        ctx->panel.prepare_prev_first = true;

        ctx->panel.backlight = rm69380_n1_create_backlight(dsi);
        if (IS_ERR(ctx->panel.backlight))
        	return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
                                     "Failed to create backlight\n");

        drm_panel_add(&ctx->panel);

        ret = mipi_dsi_attach(dsi);
        if (ret < 0) {
                drm_panel_remove(&ctx->panel);
                return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
        }

        return 0;
}

static void rm69380_n1_remove(struct mipi_dsi_device *dsi)
{
        struct rm69380_n1 *ctx = mipi_dsi_get_drvdata(dsi);
        int ret;

        ret = mipi_dsi_detach(dsi);
        if (ret < 0)
                dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

        drm_panel_remove(&ctx->panel);
}

static const struct of_device_id rm69380_n1_of_match[] = {
        { .compatible = "sharp,n1-rm69380" },
        { /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, rm69380_n1_of_match);

static struct mipi_dsi_driver rm69380_n1_driver = {
        .probe = rm69380_n1_probe,
        .remove = rm69380_n1_remove,
        .driver = {
                .name = "panel-raydium-rm69380-n1",
                .of_match_table = rm69380_n1_of_match,
        },
};
module_mipi_dsi_driver(rm69380_n1_driver);

MODULE_AUTHOR("Mias van klei <miasvanklei@outlook.com>");
MODULE_DESCRIPTION("DRM driver for RM69380 N1 Dual DSI 600Nits Video Mode Panel (1600x2560 24bpp)");
MODULE_LICENSE("GPL");
