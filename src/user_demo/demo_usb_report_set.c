/*
 * modify usb hid description test
 *
 */
#include "api.h"
#include "user.h"
#include "nds32_utils_math.h"
#include <stdint.h>

const uint8_t g_ucAudioReportDesc[] =
{
     0x05 ,0x0C /* USAGE_PAGE (CONSUMER DEVICE) */
    ,0x09 ,0x01 /* USAGE (CONSUMER CONTROL) */
    ,0xA1 ,0x01 /* COLLECTION (Application) */
    ,0x85 ,0x01 /*REPORT ID*/
    ,0x15 ,0x00 /*LOGICAL_MINIMUM (0)*/
    ,0x25 ,0x01 /*LOGICAL_MAXIMUM (1)*/
    ,0x75 ,0x01 /*REPORT CONT(1)*/
    ,0x95 ,0x01 /*REPORT SIZE(1)*/
    ,0x09 ,0xE9 /* USAGE(Volume Increment) */
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x09 ,0xEA /* USAGE(Volume Decrement) */
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x09 ,0xCD /* USAGE(Play/Pause) */
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x09 ,0xB5 /* Usage (Scan Next Track)*/
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x09 ,0xB6 /* Usage (Scan Previous Track)*/
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x09 ,0xB7 /* Usage (Stop)*/
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x09 ,0xB3 /* Usage (Fast Forward)*/
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x09 ,0xB4 /* Usage (Rewind)*/
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x05 ,0x0B /* Usage Page (Telephony)*/
    ,0x09 ,0x24 /* Usage (Redial)*/
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x09 ,0x20 /* Usage (Hook Switch)*/
    ,0x81 ,0x02 /* INPUT (Data,Var,Abs) */
    ,0x09 ,0x2F /* Usage (Phone Mute)*/
    ,0x81 ,0x06 /* Input (Data,Value,Relative,Bit Field)*/
    ,0x95 ,0x05 /* Report Count (5)*/
    ,0x81 ,0x01 /* Input (Constant,Array,Absolute,Bit Field)*/
    ,0x15 ,0x00 /*LOGICAL_MINIMUM (0)*/
    ,0x26 ,0xFF ,0x00 //Logical maximum (255)

/*************************** Begin of do-not-modify ***************************/
    ,0x06 ,0x01 ,0xFF //Usage Page (Vendor-defined 0xFF01)
    ,0x85 ,0x4B //Report Id (4B)
    ,0x75 ,0x08 //Report Size (8)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x81 ,0x03 //Input (Constant,Value,Absolute,Bit Field)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x91 ,0x02 //Output (Data,Value,Absolute,Non-volatile,Bit Field)
    ,0x85 ,0x54 //Report Id (54)
    ,0x75 ,0x08 //Report Size (8)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x81 ,0x03 //Input (Constant,Value,Absolute,Bit Field)
    ,0x95 ,0x0A //Report Count (10)
    ,0x09 ,0x00 //Usage (Vendor-defined 0x0000)
    ,0x91 ,0x02 //Output (Data,Value,Absolute,Non-volatile,Bit Field)
    ,0xC0       /* END_COLLECTION */
/*************************** End of do-not-modify ***************************/
};

void _user_schedule(void)
{
    // TODO add your own code

}

void _user_init(void)
{
    // TODO add your own code
    api_hid_report_desc_set((uint8_t*)g_ucAudioReportDesc, sizeof(g_ucAudioReportDesc));
}

