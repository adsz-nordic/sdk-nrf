#include <drivers/flash.h>
#include <dfu/pcd.h>

#if DT_NODE_HAS_STATUS(DT_INST(0, nordic_flash_nrf53_netcore_controller), okay)
#define DT_DRV_COMPAT nordic_flash_nrf53_netcore_controller
#else
#error "Node is not available"
#endif

#define FLASH_NRF53_NETCORE_CONTROLLER_NODE DT_INST(0, nordic_flash_nrf53_netcore_controller)

static int flash_netcore_read(const struct device *dev, off_t addr, void *data, size_t len)
{
	return pcd_network_core_read(addr, data, len);
}

static int flash_netcore_write(const struct device *dev, off_t addr, const void *data, size_t len)
{
	return 0;
}

static int flash_netcore_erase(const struct device *dev, off_t addr, size_t size)
{
	return 0;
}

static const struct flash_parameters *flash_netcore_get_parameters(const struct device *dev)
{
	return NULL;
}

#ifdef CONFIG_FLASH_PAGE_LAYOUT
static const struct flash_pages_layout flash_netcore_pages_layout = {
	/* TODO Use DTS to define address and region, as in flash simulator */
	.pages_count = 1,
	.pages_size = 0x40000,
};

static void flash_netcore_page_layout(const struct device *dev,
				  const struct flash_pages_layout **layout,
				  size_t *layout_size)
{
	*layout = &flash_netcore_pages_layout;
	*layout_size = 1;
}
#endif

static const struct flash_driver_api flash_netcore_api = {
	.read = flash_netcore_read,
	.write = flash_netcore_write,
	.erase = flash_netcore_erase,
	.get_parameters = flash_netcore_get_parameters,
#ifdef CONFIG_FLASH_PAGE_LAYOUT
	.page_layout = flash_netcore_page_layout,
#endif
};

static int flash_netcore_init(const struct device *dev)
{
	return 0;
}

DEVICE_DT_INST_DEFINE(	0,
			flash_netcore_init,
			NULL,
			NULL,
			NULL,
			POST_KERNEL,
			CONFIG_FLASH_INIT_PRIORITY,
			&flash_netcore_api);
