#ifndef __OPLUS_CHG_MONITOR_H__
#define __OPLUS_CHG_MONITOR_H__

#include <oplus_mms.h>

enum err_topic_item {
	ERR_ITEM_IC,
	ERR_ITEM_USBTEMP,
	ERR_ITEM_VBAT_TOO_LOW,
	ERR_ITEM_VBAT_DIFF_OVER,
	ERR_ITEM_UI_SOC_SHUTDOWN,
};

enum oplus_chg_track_mcu_voocphy_break_code {
	TRACK_VOOCPHY_BREAK_DEFAULT = 0,
	TRACK_MCU_VOOCPHY_FAST_ABSENT,
	TRACK_MCU_VOOCPHY_BAD_CONNECTED,
	TRACK_MCU_VOOCPHY_BTB_TEMP_OVER,
	TRACK_MCU_VOOCPHY_TEMP_OVER,
	TRACK_MCU_VOOCPHY_NORMAL_TEMP_FULL,
	TRACK_MCU_VOOCPHY_LOW_TEMP_FULL,
	TRACK_MCU_VOOCPHY_BAT_TEMP_EXIT,
	TRACK_MCU_VOOCPHY_DATA_ERROR,
	TRACK_MCU_VOOCPHY_HEAD_ERROR,
	TRACK_MCU_VOOCPHY_OTHER,
	TRACK_MCU_VOOCPHY_ADAPTER_FW_UPDATE,
};

enum oplus_chg_track_adsp_voocphy_break_code {
	TRACK_ADSP_VOOCPHY_BREAK_DEFAULT = 0,
	TRACK_ADSP_VOOCPHY_BAD_CONNECTED,
	TRACK_ADSP_VOOCPHY_FRAME_H_ERR,
	TRACK_ADSP_VOOCPHY_CLK_ERR,
	TRACK_ADSP_VOOCPHY_HW_VBATT_HIGH,
	TRACK_ADSP_VOOCPHY_HW_TBATT_HIGH,
	TRACK_ADSP_VOOCPHY_COMMU_TIME_OUT,
	TRACK_ADSP_VOOCPHY_ADAPTER_COPYCAT,
	TRACK_ADSP_VOOCPHY_BTB_TEMP_OVER,
	TRACK_ADSP_VOOCPHY_FULL,
	TRACK_ADSP_VOOCPHY_BATT_TEMP_OVER,
	TRACK_ADSP_VOOCPHY_SWITCH_TEMP_RANGE,
	TRACK_ADSP_VOOCPHY_OTHER,
};

enum oplus_chg_track_chg_status {
	TRACK_CHG_DEFAULT,
	TRACK_WIRED_FASTCHG_FULL,
	TRACK_WIRED_REPORT_FULL,
	TRACK_WIRED_CHG_DONE,
	TRACK_WLS_FASTCHG_FULL,
	TRACK_WLS_REPORT_FULL,
	TRACK_WLS_CHG_DONE,
};

enum oplus_chg_track_cp_voocphy_break_code {
	TRACK_CP_VOOCPHY_BREAK_DEFAULT = 0,
	TRACK_CP_VOOCPHY_FAST_ABSENT,
	TRACK_CP_VOOCPHY_BAD_CONNECTED,
	TRACK_CP_VOOCPHY_FRAME_H_ERR,
	TRACK_CP_VOOCPHY_BTB_TEMP_OVER,
	TRACK_CP_VOOCPHY_COMMU_TIME_OUT,
	TRACK_CP_VOOCPHY_ADAPTER_COPYCAT,
	TRACK_CP_VOOCPHY_FULL,
	TRACK_CP_VOOCPHY_BATT_TEMP_OVER,
	TRACK_CP_VOOCPHY_USER_EXIT_FASTCHG,
	TRACK_CP_VOOCPHY_SWITCH_TEMP_RANGE,
	TRACK_CP_VOOCPHY_CURR_LIMIT_SMALL,
	TRACK_CP_VOOCPHY_OTHER,
};

#endif /* __OPLUS_CHG_MONITOR_H__ */
