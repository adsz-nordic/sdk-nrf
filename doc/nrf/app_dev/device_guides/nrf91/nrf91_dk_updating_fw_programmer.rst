.. _nrf9161_ug_updating_fw_programmer:
.. _nrf9160_ug_updating_fw_programmer:

Updating the DK firmware using Programmer
#########################################

.. contents::
   :local:
   :depth: 2

Updating the firmware for nRF91 Series devices involves several key steps to ensure the device operates with the latest features, improvements, and security updates.
Before you begin to update the firmware, download and extract the latest application and modem firmware from the `nRF9151 DK Downloads`_, `nRF9161 DK Downloads`_, or `nRF9160 DK Downloads`_ page, depending on the DK you are using.

The downloaded ZIP archive contains the following firmware:

Application firmware
  The :file:`img_app_bl` folder contains full firmware images for different applications.
  The guides in this section use the image for the :ref:`nrf_cloud_multi_service` sample as an example.
  The nRF Cloud multi-service sample simulates sensor data and transmits it to Nordic Semiconductor's cloud solution, `nRF Cloud`_.

  The data is transmitted using either LTE-M or NB-IoT.
  The nRF Cloud multi-service sample first attempts to use LTE-M, then NB-IoT.
  Check with your SIM card provider for the mode they support at your location.

  .. tabs::

     .. group-tab:: nRF9151 DK

        * For the Onomondo SIM card, check the `Onomondo LTE-M coverage`_ and `Onomondo NB-IoT coverage`_ to see if your country is supported.

        * For the Wireless Logic SIM card, check the `Wireless Logic LTE-M/NB-IoT network coverage`_ to see if your country is supported.

     .. group-tab:: nRF9161 DK

        For the Onomondo SIM card, check the `Onomondo LTE-M coverage`_ and `Onomondo NB-IoT coverage`_ to see the network coverage for different countries.

     .. group-tab:: nRF9160 DK

        For the iBasis SIM card provided with the nRF9160 DK, see `iBasis IoT network coverage`_.

Application firmware for Device Firmware Update (DFU)
  The images in the :file:`img_fota_dfu_bin` and :file:`img_fota_dfu_hex` folders contain firmware images for DFU.
  These images are not used in the guides in this section.

Modem firmware
  The modem firmware is in a ZIP archive instead of a folder.
  The archive is named :file:`mfw_nrf9160_` or :file:`mfw_nrf91x1_`, followed by the firmware version number.
  Do not unzip this file.

The :file:`CONTENTS.txt` file in the extracted folder contains the location and names of the different firmware images.

Complete the steps in the following sections to program applications using the `Programmer app`_ from `nRF Connect for Desktop`_.
The nRF Connect for Desktop requires `SEGGER J-Link`_ |jlink_ver|.

* On Windows, the driver comes bundled with nRF Connect for Desktop.
* On macOS and Linux, you must install the driver manually.

See the `nRF Connect for Desktop's additional requirements`_ section for more details on the SEGGER J-Link driver.

You will also need the following USB cables:

* nRF91x1 DK - USB-C cable
* nRF9160 DK - micro-USB cable

.. _nrf9161_updating_fw_modem:
.. _nrf9160_updating_fw_modem:
.. _nrf9160_gs_updating_fw_modem:

Updating the modem firmware
***************************

To update the modem firmware, complete the following steps.

.. tip::
    If you experience any problems during the process, press ``Ctrl+R`` (``command+R`` on macOS) to restart the Programmer app and try again.

1. Open the Programmer app.
#. For the nRF9160 DK only: Make sure the **PROG/DEBUG SW10** switch on the nRF9160 DK is set to **nRF91**.
   On DK v0.9.0 and earlier, this is the **SW5** switch.
#. Connect the DK to the computer with a USB cable, and then turn the DK on.
#. Click :guilabel:`SELECT DEVICE` and select the DK from the drop-down list.

   .. tabs::

      .. group-tab:: nRF91x1 DK

         .. figure:: images/programmer_select_device_nrf9151.png
            :alt: Programmer - Select device (nRF9151 DK shown)

            Programmer - Select device (nRF9151 DK shown)

      .. group-tab:: nRF9160 DK

         .. figure:: images/programmer_selectdevice_nrf9160.png
            :alt: Programmer - Select device

            Programmer - Select device

   The drop-down text changes to the type of the selected device, with its SEGGER ID below the name.
   The **Device memory layout** section also changes its name to the device name, and indicates that the device is connected.
   If the :guilabel:`Auto read memory` option is selected in the **J-LINK SETTINGS** section of the side panel, the memory layout will update.
   If it is not selected and you wish to see the memory layout, click :guilabel:`Read` in the **DEVICE** section of the side panel.

#. Click :guilabel:`Add file` in the **FILE** section, and select :guilabel:`Browse`.
#. Navigate to where you extracted the firmware, and select the file for your DK:

   * nRF9160 DK - :file:`mfw_nrf9160_<version-number>.zip`
   * nRF91x1 DK - :file:`mfw_nrf91x1_<version-number>.zip`

#. Click :guilabel:`Write` in the **DEVICE** section of the side panel.

   .. tabs::

      .. group-tab:: nRF91x1 DK

         .. figure:: images/programmer_hex_write_nrf9151.png
            :alt: Programmer - Write (nRF9151 DK shown)

            Programmer - Write (nRF9151 DK shown)

      .. group-tab:: nRF9160 DK

         .. figure:: images/programmer_write_nrf9160dk.png
            :alt: Programmer - Write

            Programmer - Write

   The **Modem DFU** window appears.

   .. tabs::

      .. group-tab:: nRF91x1 DK

         .. figure:: images/programmerapp_modemdfu_nrf9151.png
            :alt: Modem DFU window (nRF9151 DK shown)

            The Modem DFU window (nRF9151 DK shown)

      .. group-tab:: nRF9160 DK

         .. figure:: images/programmerapp_modemdfu.png
            :alt: Modem DFU window

            The Modem DFU window

#. Ignore the warning message and click the :guilabel:`Write` button in the **Modem DFU** window to update the firmware.
   Do not unplug or turn off the device during this process.

When the update is complete, you see a success message.
If you update the application firmware now, you can skip the initial steps about connecting and selecting the device in :ref:`nrf9160_updating_fw_application`.

.. note::

   If you experience problems updating the modem firmware, click :guilabel:`Erase all` in the **DEVICE** section of the side panel and try updating again.

.. _nrf9161_updating_fw_application:
.. _nrf9160_updating_fw_application:
.. _nrf9160_gs_updating_fw_application:

Updating the application firmware
*********************************

To update the application firmware using the Programmer app, complete the following steps.

.. tip::
    If you experience any problems during the process, press ``Ctrl+R`` (``command+R`` on macOS) to restart the Programmer app and try again.

1. Open the Programmer app.
#. For the nRF9160 DK only: Make sure the **PROG/DEBUG SW10** switch (**SW5** on DK v0.9.0 and earlier) on the nRF9160 DK is set to **nRF91** or **nRF52** as appropriate for the application or sample you are programming.
   See the `Device programming section in the nRF9160 DK User Guide`_ for more information.

   For the :ref:`nrf_cloud_multi_service` sample, the switch must be set to **nRF91**.

#. Connect the DK to the computer with a USB cable, and then turn the DK on.
#. Click :guilabel:`SELECT DEVICE` and select the DK from the drop-down list.

   .. tabs::

      .. group-tab:: nRF91x1 DK

         .. figure:: images/programmer_select_device_nrf9151.png
            :alt: Programmer - Select device (nRF9151 DK shown)

            Programmer - Select device (nRF9151 DK shown)

      .. group-tab:: nRF9160 DK

         .. figure:: images/programmer_selectdevice_nrf9160.png
            :alt: Programmer - Select device

            Programmer - Select device

   The drop-down text changes to the type of the selected device, with its SEGGER ID below the name.
   The **Device memory layout** section also changes its name to the device name, and indicates that the device is connected.
   If the :guilabel:`Auto read memory` option is selected in the **J-LINK SETTINGS** section, the memory layout will update.
   If it is not selected and you wish to see the memory layout, click :guilabel:`Read` in the **DEVICE** section.

#. Click :guilabel:`Add file` in the **FILE** section, and select :guilabel:`Browse`.
#. Navigate to where you extracted the firmware, and then to the :file:`img_app_bl` folder there.
#. Select the :file:`.hex` file for your DK for the application you are programming:

   * nRF9160 DK - :file:`nrf9160dk_nrfcloud_multi_service_coap_<version-number>.hex`
   * nRF91x1 DK - :file:`nrf9151dk_nrfcloud_multi_service_coap_<version-number>.hex` or :file:`nrf9161dk_nrfcloud_multi_service_coap_<version-number>.hex`

#. Click the :guilabel:`Erase & write` button in the **DEVICE** section to program the DK.
   Do not unplug or turn off the DK during this process.

   .. tabs::

      .. group-tab:: nRF91x1 DK

         .. figure:: images/programmer_erasewrite_nrf9151dk.png
            :alt: Programmer - Erase & write (nRF9151 DK shown)

            Programmer - Erase & write (nRF9151 DK shown)

      .. group-tab:: nRF9160 DK

         .. figure:: images/programmer_erasewrite_nrf9160dk.png
            :alt: Programmer - Erase & write

            Programmer - Erase & write
