/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2021,2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */
#ifndef __QCOM_IO_PGTABLE_ALLOC_H
#define __QCOM_IO_PGTABLE_ALLOC_H

#include <linux/mm.h>
#include "drivers/iommu/iommu-pages.h"

/* One zeroed, accounted page table page from the IOMMU page allocator */
static inline struct page *qcom_iommu_alloc_pt_page(gfp_t gfp)
{
	void *virt = iommu_alloc_pages_sz(gfp, PAGE_SIZE);

	return virt ? virt_to_page(virt) : NULL;
}

static inline void qcom_iommu_free_pt_page(struct page *page)
{
	iommu_free_pages(page_address(page));
}

int qcom_io_pgtable_allocator_register(u32 vmid);
void qcom_io_pgtable_allocator_unregister(u32 vmid);
struct page *qcom_io_pgtable_alloc_page(u32 vmid, gfp_t gfp);
void qcom_io_pgtable_free_page(struct page *page);
int qcom_io_pgtable_alloc_init(void);
void qcom_io_pgtable_alloc_exit(void);

#endif /* __QCOM_IO_PGTABLE_ALLOC_H */

