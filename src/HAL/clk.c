#include "comm.h"
#include "reg_apb.h"
#include "clk.h"

void HAL_CLK_OHPQ_Div_Set(uint8_t osc_div_sel, uint8_t ahb_div_sel, uint8_t apb_div_sel, uint8_t qspi_div_sel)
{
    uint8_t uc_tdmlrclksel; 
    uint8_t uc_tdmmclksel; 
    uint8_t uc_i2sevalclksel; 
    uint8_t uc_i2smsclksel; 
    uint8_t uc_i2smmclksel; 
    uint8_t uc_clkmclkdivsel; 
    uint8_t uc_clkuartdivsel; 
    uint8_t uc_caliclksel; 
    uint8_t uc_clki2cdivsel; 
    uint8_t uc_clkqspidivsel; 
    uint8_t uc_clkahbdivsel; 
    uint8_t uc_clkapbdivsel; 
    uint8_t uc_clkoschighdivsel;

apb_clk_gen_clksel_unpack(
    &uc_tdmlrclksel, 
    &uc_tdmmclksel, 
    &uc_i2sevalclksel, 
    &uc_i2smsclksel, 
    &uc_i2smmclksel, 
    &uc_clkmclkdivsel, 
    &uc_clkuartdivsel, 
    &uc_caliclksel, 
    &uc_clki2cdivsel, 
    &uc_clkqspidivsel, 
    &uc_clkahbdivsel, 
    &uc_clkapbdivsel, 
    &uc_clkoschighdivsel);

apb_clk_gen_clksel_pack(
    uc_tdmlrclksel, 
    uc_tdmmclksel, 
    uc_i2sevalclksel, 
    uc_i2smsclksel, 
    uc_i2smmclksel, 
    uc_clkmclkdivsel, 
    uc_clkuartdivsel,
    uc_caliclksel, 
    uc_clki2cdivsel, 
    qspi_div_sel, 
    ahb_div_sel, 
    apb_div_sel, 
    osc_div_sel); 
}
