.. _fprotect_readme:

Hardware flash write protection
###############################

.. contents::
   :local:
   :depth: 2

The hardware flash write protection driver (``fprotect``) can be used to protect flash areas from writing.
The driver uses a hardware peripheral (ACL, BPROT, RRAMC, or SPU, depending on the chip model) to protect the area.
The protection is irreversible until a reset occurs.

Configuration
*************

To use the hardware flash write protection driver, enable the :kconfig:option:`CONFIG_FPROTECT` Kconfig option.

For additional configuration, see the `CONFIG_FPROTECT_*`_ Kconfig options.

Usage example
*************

The following example shows how to protect ``PM_B0_SIZE`` bytes of the flash area starting from ``PM_B0_ADDRESS``:

.. code-block:: c

   int err = fprotect_area(PM_B0_ADDRESS, PM_B0_SIZE);

API documentation
*****************

| Header file: :file:`include/fprotect.h`
| Source files: :file:`lib/fprotect/`

.. doxygengroup:: fprotect
