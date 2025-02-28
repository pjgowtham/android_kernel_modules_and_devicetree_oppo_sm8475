// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2020-2022 Oplus. All rights reserved.
 */

#ifndef HYBRIDSWAP_H
#define HYBRIDSWAP_H

extern unsigned long try_to_free_mem_cgroup_pages(struct mem_cgroup *memcg,
						  unsigned long nr_pages,
						  gfp_t gfp_mask,
						  bool may_swap);


extern int __init hybridswap_pre_init(void);
extern ssize_t hybridswap_vmstat_show(struct device *dev,
				      struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_loglevel_store(struct device *dev,
					 struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hybridswap_loglevel_show(struct device *dev,
					struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_enable_store(struct device *dev,
				       struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hybridswap_enable_show(struct device *dev,
				      struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_swapd_zram_init_show(struct device *dev,
		struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_swapd_zram_init_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t len);

#ifdef CONFIG_HYBRIDSWAP_CORE
extern void hybridswap_track(struct zram *zram, u32 index, struct mem_cgroup *memcg);
extern void hybridswap_untrack(struct zram *zram, u32 index);
extern int hybridswap_fault_out(struct zram *zram, u32 index);
extern bool hybridswap_delete(struct zram *zram, u32 index);

extern ssize_t hybridswap_report_show(struct device *dev,
				      struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_stat_snap_show(struct device *dev,
					 struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_meminfo_show(struct device *dev,
				       struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_core_enable_store(struct device *dev,
					    struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hybridswap_core_enable_show(struct device *dev,
					   struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_loop_device_store(struct device *dev,
					    struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hybridswap_loop_device_show(struct device *dev,
					   struct device_attribute *attr, char *buf);
extern ssize_t backing_dev_store(struct device *dev,
				 struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t backing_dev_show(struct device *dev,
				struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_dev_life_store(struct device *dev,
					 struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hybridswap_dev_life_show(struct device *dev,
					struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_quota_day_store(struct device *dev,
					  struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hybridswap_quota_day_show(struct device *dev,
					 struct device_attribute *attr, char *buf);
extern ssize_t hybridswap_zram_increase_store(struct device *dev,
					      struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hybridswap_zram_increase_show(struct device *dev,
					     struct device_attribute *attr, char *buf);
extern void hybridswap_unbind(struct zram *zram);
#endif

#ifdef CONFIG_HYBRIDSWAP_SWAPD
extern ssize_t hybridswap_swapd_pause_store(struct device *dev,
					    struct device_attribute *attr, const char *buf, size_t len);
extern ssize_t hybridswap_swapd_pause_show(struct device *dev,
					   struct device_attribute *attr, char *buf);
extern bool current_is_hybrid_swapd(void);
#endif

#ifdef CONFIG_CONT_PTE_HUGEPAGE
extern int get_cont_pte_pool_high(void);
#endif
#endif /* HYBRIDSWAP_H */
