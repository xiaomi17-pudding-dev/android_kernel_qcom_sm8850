load(":drivers/block/zram/modules.bzl", register_zram = "register_modules")

def register_modules(registry):
    # android17-6.18: the vendor zram (QPACE) is not ported; the GKI module is used
    # register_zram(registry)

    registry.register(
        name = "drivers/block/virtio_blk",
        out = "virtio_block.ko",
        config = "CONFIG_VIRTIO_BLK",
        srcs = [
            # do not sort
            "drivers/block/virtio_blk.c",
        ],
        hdrs = [
            "drivers/block/virtio_blk_qti_crypto.h",
        ],
        deps = [
            # do not sort
            "drivers/block/virtio_blk_qti_crypto",
        ],
    )

    registry.register(
        name = "drivers/block/virtio_blk_qti_crypto",
        out = "virtio_blk_qti_crypto.ko",
        config = "CONFIG_VIRTIO_BLK_QTI_CRYPTO",
        srcs = [
            # do not sort
            "drivers/block/virtio_blk_qti_crypto.c",
        ],
        hdrs = [
            "drivers/block/virtio_blk_qti_crypto.h",
        ],
        deps = [
            # do not sort
            "drivers/soc/qcom/crypto-qti-virt",
        ],
    )
