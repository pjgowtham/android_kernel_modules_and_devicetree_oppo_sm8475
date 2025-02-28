/***************************************************************
** Copyright (C), 2022, OPLUS Mobile Comm Corp., Ltd
** File : oplus_display_temperature.h
** Description : oplus_display_temperature header
** Version : 1.0
** Date : 2022/11/20
** Author : Display
***************************************************************/

#ifndef _OPLUS_DISPLAY_TEMPERATURE_H_
#define _OPLUS_DISPLAY_TEMPERATURE_H_

/* please just only include linux common head file to keep me pure */
#include <linux/iio/consumer.h>

enum oplus_display_dbv_index {
	OPLUS_DISPLAY_GREATER_THAN_3515_DBV_INDEX = 0,		/* dbv > 3515 */
	OPLUS_DISPLAY_1604_3515_DBV_INDEX = 1,				/* 1604 <= dbv <= 3515 */
	OPLUS_DISPLAY_1511_1604_DBV_INDEX = 2,				/* 1511 <= dbv < 1604 */
	OPLUS_DISPLAY_1419_1511_DBV_INDEX = 3,				/* 1419 <= dbv < 1511 */
	OPLUS_DISPLAY_1328_1419_DBV_INDEX = 4,				/* 1328 <= dbv < 1419 */
	OPLUS_DISPLAY_1212_1328_DBV_INDEX = 5,				/* 1212 <= dbv < 1328 */
	OPLUS_DISPLAY_1096_1212_DBV_INDEX = 6,				/* 1096 <= dbv < 1212 */
	OPLUS_DISPLAY_950_1096_DBV_INDEX = 7,				/* 950 <= dbv < 1096 */
	OPLUS_DISPLAY_761_950_DBV_INDEX = 8,				/* 761 <= dbv < 950 */
	OPLUS_DISPLAY_544_761_DBV_INDEX = 9,				/* 544 <= dbv < 761 */
	OPLUS_DISPLAY_LESS_THAN_544_DBV_INDEX = 10,			/* dbv < 544 */
};

enum oplus_display_temp_index {
	OPLUS_DISPLAY_LESS_THAN_MINUS10_TEMP_INDEX = 0,		/* -20 ~ -10 */
	OPLUS_DISPLAY_MINUS10_0_TEMP_INDEX = 1,				/* -10 ~ 0 */
	OPLUS_DISPLAY_0_10_TEMP_INDEX = 2,					/* 0 ~ 10 */
	OPLUS_DISPLAY_10_20_TEMP_INDEX = 3,					/* 10 ~ 20 */
	OPLUS_DISPLAY_20_25_TEMP_INDEX = 4,					/* 20 ~ 25 */
	OPLUS_DISPLAY_25_30_TEMP_INDEX = 5,					/* 25 ~ 30 */
	OPLUS_DISPLAY_30_35_TEMP_INDEX = 6,					/* 30 ~ 35 */
	OPLUS_DISPLAY_35_40_TEMP_INDEX = 7,					/* 35 ~ 40 */
	OPLUS_DISPLAY_40_45_TEMP_INDEX = 8,					/* 40 ~ 45 */
	OPLUS_DISPLAY_45_50_TEMP_INDEX = 9,					/* 45 ~ 50 */
	OPLUS_DISPLAY_GREATER_THAN_50_TEMP_INDEX = 10,		/* > 50 */
};

struct oplus_display_temp {
	struct iio_channel *ntc_temp_chan;
	struct workqueue_struct *oplus_compensation_set_wq;		/* a workqueue used to send compensation set */
	struct work_struct oplus_compensation_set_work;			/* a work struct used to send compensation set */
	int cmd_delay;
	bool compensation_enable;
	int ntc_temp;
	int shell_temp;
	bool fake_ntc_temp;
	bool fake_shell_temp;
	bool tc_dry_run;
};

/* ntc temp */
void oplus_compensation_set_work_handler(struct work_struct *work_item);
int oplus_display_change_compensation_params_ref_reg(void *dsi_display);
int oplus_display_register_ntc_channel(void *dsi_display);
int oplus_display_get_ntc_temp(void);
ssize_t oplus_display_get_ntc_temp_attr(struct kobject *obj,
	struct kobj_attribute *attr, char *buf);
ssize_t oplus_display_set_ntc_temp_attr(struct kobject *obj,
	struct kobj_attribute *attr, const char *buf, size_t count);
/* shell temp */
int oplus_display_get_shell_temp(void);
ssize_t oplus_display_get_shell_temp_attr(struct kobject *obj,
	struct kobj_attribute *attr, char *buf);
ssize_t oplus_display_set_shell_temp_attr(struct kobject *obj,
	struct kobj_attribute *attr, const char *buf, size_t count);
/* cmd delay */
int oplus_display_get_cmd_delay(void);
ssize_t oplus_display_get_cmd_delay_attr(struct kobject *obj,
	struct kobj_attribute *attr, char *buf);
ssize_t oplus_display_set_cmd_delay_attr(struct kobject *obj,
	struct kobj_attribute *attr, const char *buf, size_t count);
/* compensation enable */
ssize_t oplus_display_get_compensation_enable_attr(struct kobject *obj,
	struct kobj_attribute *attr, char *buf);
ssize_t oplus_display_set_compensation_enable_attr(struct kobject *obj,
	struct kobj_attribute *attr, const char *buf, size_t count);
/* queue compensation set */
void oplus_display_queue_compensation_set_work(void);
/* temp ompensation */
int oplus_display_temp_compensation_set(void *display_panel, bool force_set);
int oplus_display_temp_check(void *display);
ssize_t oplus_temp_compensation_set_tc_dry_run_attr(struct kobject *obj,
	struct kobj_attribute *attr, const char *buf, size_t count);
ssize_t oplus_temp_compensation_get_tc_dry_run_attr(struct kobject *obj,
	struct kobj_attribute *attr, char *buf);

#endif /* _OPLUS_DISPLAY_TEMPERATURE_H_ */
