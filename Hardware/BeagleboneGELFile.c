//####################################################
//Beaglebone GEL file
//v1.0 Mar9,2012
//v1.1 May2,2012  Streamlined DDR PHY configuration routines
//v1.2 May3,2012  Fixed max DDR PLL config to 266MHz
//####################################################

#include "BeagleboneGELFile.h"

//****************************************************
//PRCM module definitions
//****************************************************
#define PRCM_BASE_ADDR                    (0x44E00000)
#define CM_PER_EMIF_CLKCTRL               (PRCM_BASE_ADDR + 0x028)
#define CM_PER_EMIF_FW_CLKCTRL            (PRCM_BASE_ADDR + 0x0D0)

#define CM_AUTOIDLE_DPLL_MPU              (PRCM_BASE_ADDR + 0x41C)
#define CM_IDLEST_DPLL_MPU                (PRCM_BASE_ADDR + 0x420)
#define CM_CLKSEL_DPLL_MPU                (PRCM_BASE_ADDR + 0x42C)
#define CM_AUTOIDLE_DPLL_DDR              (PRCM_BASE_ADDR + 0x430)
#define CM_IDLEST_DPLL_DDR                (PRCM_BASE_ADDR + 0x434)
#define CM_CLKSEL_DPLL_DDR                (PRCM_BASE_ADDR + 0x440)
#define CM_AUTOIDLE_DPLL_DISP             (PRCM_BASE_ADDR + 0x444)
#define CM_IDLEST_DPLL_DISP               (PRCM_BASE_ADDR + 0x448)
#define CM_CLKSEL_DPLL_DISP               (PRCM_BASE_ADDR + 0x454)
#define CM_AUTOIDLE_DPLL_CORE             (PRCM_BASE_ADDR + 0x458)
#define CM_IDLEST_DPLL_CORE               (PRCM_BASE_ADDR + 0x45C)
#define CM_CLKSEL_DPLL_CORE               (PRCM_BASE_ADDR + 0x468)
#define CM_AUTOIDLE_DPLL_PER              (PRCM_BASE_ADDR + 0x46C)
#define CM_IDLEST_DPLL_PER                (PRCM_BASE_ADDR + 0x470)
#define CM_CLKSEL_DPLL_PER                (PRCM_BASE_ADDR + 0x49C)

#define CM_DIV_M4_DPLL_CORE               (PRCM_BASE_ADDR + 0x480)
#define CM_DIV_M5_DPLL_CORE               (PRCM_BASE_ADDR + 0x484)
#define CM_CLKMODE_DPLL_MPU               (PRCM_BASE_ADDR + 0x488)
#define CM_CLKMODE_DPLL_PER               (PRCM_BASE_ADDR + 0x48C)
#define CM_CLKMODE_DPLL_CORE              (PRCM_BASE_ADDR + 0x490)
#define CM_CLKMODE_DPLL_DDR               (PRCM_BASE_ADDR + 0x494)
#define CM_CLKMODE_DPLL_DISP              (PRCM_BASE_ADDR + 0x498)

#define CM_DIV_M2_DPLL_DDR                (PRCM_BASE_ADDR + 0x4A0)
#define CM_DIV_M2_DPLL_DISP               (PRCM_BASE_ADDR + 0x4A4)
#define CM_DIV_M2_DPLL_MPU                (PRCM_BASE_ADDR + 0x4A8)
#define CM_DIV_M2_DPLL_PER                (PRCM_BASE_ADDR + 0x4AC)
#define CM_DIV_M6_DPLL_CORE               (PRCM_BASE_ADDR + 0x4D8)

#define CM_CLKOUT_CTRL                    (PRCM_BASE_ADDR + 0x700)

//****************************************************
//Control module definitions
//****************************************************

#define CONTROL_BASE_ADDR       (0x44E10000)

#define CONTROL_STATUS          (CONTROL_BASE_ADDR + 0x40)
#define CONF_XDMA_EVENT_INTR1   (CONTROL_BASE_ADDR + 0x9b4)

//DDR IO Control Registers
#define DDR_IO_CTRL             (CONTROL_BASE_ADDR + 0x0E04)
#define VTP_CTRL_REG            (CONTROL_BASE_ADDR + 0x0E0C)
#define DDR_CKE_CTRL            (CONTROL_BASE_ADDR + 0x131C)
#define DDR_CMD0_IOCTRL         (CONTROL_BASE_ADDR + 0x1404)
#define DDR_CMD1_IOCTRL         (CONTROL_BASE_ADDR + 0x1408)
#define DDR_CMD2_IOCTRL         (CONTROL_BASE_ADDR + 0x140C)
#define DDR_DATA0_IOCTRL        (CONTROL_BASE_ADDR + 0x1440)
#define DDR_DATA1_IOCTRL        (CONTROL_BASE_ADDR + 0x1444)

//********************************************************************
//EMIF4DC module definitions
//********************************************************************
#define EMIF_BASE_ADDR                    (0x4C000000)
#define EMIF_STATUS_REG                   (EMIF_BASE_ADDR + 0x004)
#define EMIF_SDRAM_CONFIG_REG             (EMIF_BASE_ADDR + 0x008)
#define EMIF_SDRAM_CONFIG_2_REG           (EMIF_BASE_ADDR + 0x00C)
#define EMIF_SDRAM_REF_CTRL_REG           (EMIF_BASE_ADDR + 0x010)
#define EMIF_SDRAM_REF_CTRL_SHDW_REG      (EMIF_BASE_ADDR + 0x014)
#define EMIF_SDRAM_TIM_1_REG              (EMIF_BASE_ADDR + 0x018)
#define EMIF_SDRAM_TIM_1_SHDW_REG         (EMIF_BASE_ADDR + 0x01C)
#define EMIF_SDRAM_TIM_2_REG              (EMIF_BASE_ADDR + 0x020)
#define EMIF_SDRAM_TIM_2_SHDW_REG         (EMIF_BASE_ADDR + 0x024)
#define EMIF_SDRAM_TIM_3_REG              (EMIF_BASE_ADDR + 0x028)
#define EMIF_SDRAM_TIM_3_SHDW_REG         (EMIF_BASE_ADDR + 0x02C)
#define EMIF_LPDDR2_NVM_TIM_REG           (EMIF_BASE_ADDR + 0x030)
#define EMIF_LPDDR2_NVM_TIM_SHDW_REG      (EMIF_BASE_ADDR + 0x034)
#define EMIF_PWR_MGMT_CTRL_REG            (EMIF_BASE_ADDR + 0x038)
#define EMIF_PWR_MGMT_CTRL_SHDW_REG       (EMIF_BASE_ADDR + 0x03C)
#define EMIF_LPDDR2_MODE_REG_DATA_REG     (EMIF_BASE_ADDR + 0x040)
#define EMIF_LPDDR2_MODE_REG_CFG_REG      (EMIF_BASE_ADDR + 0x050)
#define EMIF_OCP_CONFIG_REG               (EMIF_BASE_ADDR + 0x054)
#define EMIF_OCP_CFG_VAL_1_REG            (EMIF_BASE_ADDR + 0x058)
#define EMIF_OCP_CFG_VAL_2_REG            (EMIF_BASE_ADDR + 0x05C)
#define EMIF_IODFT_TLGC_REG               (EMIF_BASE_ADDR + 0x060)
#define EMIF_IODFT_CTRL_MISR_RSLT_REG     (EMIF_BASE_ADDR + 0x064)
#define EMIF_IODFT_ADDR_MISR_RSLT_REG     (EMIF_BASE_ADDR + 0x068)
#define EMIF_IODFT_DATA_MISR_RSLT_1_REG   (EMIF_BASE_ADDR + 0x06C)
#define EMIF_IODFT_DATA_MISR_RSLT_2_REG   (EMIF_BASE_ADDR + 0x070)
#define EMIF_IODFT_DATA_MISR_RSLT_3_REG   (EMIF_BASE_ADDR + 0x074)
#define EMIF_PERF_CNT_1_REG               (EMIF_BASE_ADDR + 0x080)
#define EMIF_PERF_CNT_2_REG               (EMIF_BASE_ADDR + 0x084)
#define EMIF_PERF_CNT_CFG_REG             (EMIF_BASE_ADDR + 0x088)
#define EMIF_PERF_CNT_SEL_REG             (EMIF_BASE_ADDR + 0x08C)
#define EMIF_PERF_CNT_TIM_REG             (EMIF_BASE_ADDR + 0x090)
#define EMIF_READ_IDLE_CTRL_REG           (EMIF_BASE_ADDR + 0x098)
#define EMIF_READ_IDLE_CTRL_SHDW_REG      (EMIF_BASE_ADDR + 0x09C)
#define EMIF_IRQ_EOI_REG                  (EMIF_BASE_ADDR + 0x0A0)
#define EMIF_IRQSTATUS_RAW_SYS_REG        (EMIF_BASE_ADDR + 0x0A4)
#define EMIF_IRQSTATUS_SYS_REG            (EMIF_BASE_ADDR + 0x0AC)
#define EMIF_IRQENABLE_SET_SYS_REG        (EMIF_BASE_ADDR + 0x0B4)
#define EMIF_IRQENABLE_CLR_SYS_REG        (EMIF_BASE_ADDR + 0x0BC)
#define EMIF_ZQ_CONFIG_REG                (EMIF_BASE_ADDR + 0x0C8)
#define EMIF_TEMP_ALERT_CONFIG_REG        (EMIF_BASE_ADDR + 0x0CC)
#define EMIF_OCP_ERR_LOG_REG              (EMIF_BASE_ADDR + 0x0D0)
#define EMIF_RDWR_LVL_RMP_WIN_REG         (EMIF_BASE_ADDR + 0x0D4)
#define EMIF_RDWR_LVL_RMP_CTRL_REG        (EMIF_BASE_ADDR + 0x0D8)
#define EMIF_RDWR_LVL_CTRL_REG            (EMIF_BASE_ADDR + 0x0DC)
#define EMIF_DDR_PHY_CTRL_1_REG           (EMIF_BASE_ADDR + 0x0E4)
#define EMIF_DDR_PHY_CTRL_1_SHDW_REG      (EMIF_BASE_ADDR + 0x0E8)
#define EMIF_DDR_PHY_CTRL_2_REG           (EMIF_BASE_ADDR + 0x0EC)
#define EMIF_PRI_COS_MAP_REG              (EMIF_BASE_ADDR + 0x100)
#define EMIF_CONNID_COS_1_MAP_REG         (EMIF_BASE_ADDR + 0x104)
#define EMIF_CONNID_COS_2_MAP_REG         (EMIF_BASE_ADDR + 0x108)
#define EMIF_RD_WR_EXEC_THRSH_REG         (EMIF_BASE_ADDR + 0x120)


//*******************************************************************
//DDR PHY registers
//*******************************************************************
#define    DDR_PHY_BASE_ADDR                                   (0x44E12000)
//CMD0
#define    CMD0_REG_PHY_CTRL_SLAVE_RATIO_0                     (0x01C + DDR_PHY_BASE_ADDR)
#define    CMD0_REG_PHY_CTRL_SLAVE_FORCE_0                     (0x020 + DDR_PHY_BASE_ADDR)
#define    CMD0_REG_PHY_CTRL_SLAVE_DELAY_0                     (0x024 + DDR_PHY_BASE_ADDR)
#define    CMD0_REG_PHY_DLL_LOCK_DIFF_0                        (0x028 + DDR_PHY_BASE_ADDR)
#define    CMD0_REG_PHY_INVERT_CLKOUT_0                        (0x02C + DDR_PHY_BASE_ADDR)
#define    CMD0_PHY_REG_STATUS_PHY_CTRL_DLL_LOCK_0             (0x030 + DDR_PHY_BASE_ADDR)
#define    CMD0_PHY_REG_STATUS_PHY_CTRL_OF_IN_LOCK_STATE_0     (0x034 + DDR_PHY_BASE_ADDR)
#define    CMD0_PHY_REG_STATUS_PHY_CTRL_OF_IN_DELAY_VALUE_0    (0x038 + DDR_PHY_BASE_ADDR)
#define    CMD0_PHY_REG_STATUS_PHY_CTRL_OF_OUT_DELAY_VALUE_0   (0x03C + DDR_PHY_BASE_ADDR)

//CMD1
#define    CMD1_REG_PHY_CTRL_SLAVE_RATIO_0                     (0x050 + DDR_PHY_BASE_ADDR)
#define    CMD1_REG_PHY_CTRL_SLAVE_FORCE_0                     (0x054 + DDR_PHY_BASE_ADDR)
#define    CMD1_REG_PHY_CTRL_SLAVE_DELAY_0                     (0x058 + DDR_PHY_BASE_ADDR)
#define    CMD1_REG_PHY_DLL_LOCK_DIFF_0                        (0x05C + DDR_PHY_BASE_ADDR)
#define    CMD1_REG_PHY_INVERT_CLKOUT_0                        (0x060 + DDR_PHY_BASE_ADDR)
#define    CMD1_PHY_REG_STATUS_PHY_CTRL_DLL_LOCK_0             (0x064 + DDR_PHY_BASE_ADDR)
#define    CMD1_PHY_REG_STATUS_PHY_CTRL_OF_IN_LOCK_STATE_0     (0x068 + DDR_PHY_BASE_ADDR)
#define    CMD1_PHY_REG_STATUS_PHY_CTRL_OF_IN_DELAY_VALUE_0    (0x06C + DDR_PHY_BASE_ADDR)
#define    CMD1_PHY_REG_STATUS_PHY_CTRL_OF_OUT_DELAY_VALUE_0   (0x070 + DDR_PHY_BASE_ADDR)

//CMD2
#define    CMD2_REG_PHY_CTRL_SLAVE_RATIO_0                     (0x084 + DDR_PHY_BASE_ADDR)
#define    CMD2_REG_PHY_CTRL_SLAVE_FORCE_0                     (0x088 + DDR_PHY_BASE_ADDR)
#define    CMD2_REG_PHY_CTRL_SLAVE_DELAY_0                     (0x08C + DDR_PHY_BASE_ADDR)
#define    CMD2_REG_PHY_DLL_LOCK_DIFF_0                        (0x090 + DDR_PHY_BASE_ADDR)
#define    CMD2_REG_PHY_INVERT_CLKOUT_0                        (0x094 + DDR_PHY_BASE_ADDR)
#define    CMD2_PHY_REG_STATUS_PHY_CTRL_DLL_LOCK_0             (0x098 + DDR_PHY_BASE_ADDR)
#define    CMD2_PHY_REG_STATUS_PHY_CTRL_OF_IN_LOCK_STATE_0     (0x09C + DDR_PHY_BASE_ADDR)
#define    CMD2_PHY_REG_STATUS_PHY_CTRL_OF_IN_DELAY_VALUE_0    (0x0A0 + DDR_PHY_BASE_ADDR)
#define    CMD2_PHY_REG_STATUS_PHY_CTRL_OF_OUT_DELAY_VALUE_0   (0x0A4 + DDR_PHY_BASE_ADDR)

//DATA0
#define    DATA0_REG_PHY_DATA_SLICE_IN_USE_0                   (0x0B8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_DIS_CALIB_RST_0                       (0x0BC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RDC_FIFO_RST_ERR_CNT_CLR_0            (0x0C0 + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_RDC_FIFO_RST_ERR_CNT_0                    (0x0C4 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_0                  (0x0C8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_1                  (0x0CC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_FORCE_0                  (0x0D0 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_DELAY_0                  (0x0D4 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_RD_DQS_SLAVE_DELAY_1                  (0x0D8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_0                  (0x0DC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_1                  (0x0E0 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_FORCE_0                  (0x0E4 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_DELAY_0                  (0x0E8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DQS_SLAVE_DELAY_1                  (0x0EC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WRLVL_INIT_RATIO_0                    (0x0F0 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WRLVL_INIT_RATIO_1                    (0x0F4 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WRLVL_INIT_MODE_0                     (0x0F8 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_GATELVL_INIT_RATIO_0                  (0x0FC + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_GATELVL_INIT_RATIO_1                  (0x100 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_GATELVL_INIT_MODE_0                   (0x104 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_0                 (0x108 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_1                 (0x10C + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_IN_FORCE_0                    (0x110 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_IN_DELAY_0                    (0x114 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_FIFO_WE_IN_DELAY_1                    (0x118 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_DQ_OFFSET_0                           (0x11C + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_0                 (0x120 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_1                 (0x124 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_FORCE_0                 (0x128 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_DELAY_0                 (0x12C + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_WR_DATA_SLAVE_DELAY_1                 (0x130 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_USE_RANK0_DELAYS_0                    (0x134 + DDR_PHY_BASE_ADDR)
#define    DATA0_REG_PHY_DLL_LOCK_DIFF_0                       (0x138 + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_REG_STATUS_DLL_LOCK_0                     (0x13C + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_REG_STATUS_OF_IN_LOCK_STATE_0             (0x140 + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_REG_STATUS_OF_IN_DELAY_VALUE_0            (0x144 + DDR_PHY_BASE_ADDR)
#define    DATA0_PHY_REG_STATUS_OF_OUT_DELAY_VALUE_0           (0x148 + DDR_PHY_BASE_ADDR)

//DATA1
#define    DATA1_REG_PHY_DATA_SLICE_IN_USE_0                   (0x15C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_DIS_CALIB_RST_0                       (0x160 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RDC_FIFO_RST_ERR_CNT_CLR_0            (0x164 + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_RDC_FIFO_RST_ERR_CNT_0                    (0x168 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_RATIO_0                  (0x16C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_RATIO_1                  (0x170 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_FORCE_0                  (0x174 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_DELAY_0                  (0x178 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_RD_DQS_SLAVE_DELAY_1                  (0x17C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_RATIO_0                  (0x180 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_RATIO_1                  (0x184 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_FORCE_0                  (0x188 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_DELAY_0                  (0x18C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DQS_SLAVE_DELAY_1                  (0x190 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WRLVL_INIT_RATIO_0                    (0x194 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WRLVL_INIT_RATIO_1                    (0x198 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WRLVL_INIT_MODE_0                     (0x19C + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_GATELVL_INIT_RATIO_0                  (0x1A0 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_GATELVL_INIT_RATIO_1                  (0x1A4 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_GATELVL_INIT_MODE_0                   (0x1A8 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_SLAVE_RATIO_0                 (0x1AC + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_SLAVE_RATIO_1                 (0x1B0 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_IN_FORCE_0                    (0x1B4 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_IN_DELAY_0                    (0x1B8 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_FIFO_WE_IN_DELAY_1                    (0x1BC + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_DQ_OFFSET_0                           (0x1C0 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_RATIO_0                 (0x1C4 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_RATIO_1                 (0x1C8 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_FORCE_0                 (0x1CC + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_DELAY_0                 (0x1D0 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_WR_DATA_SLAVE_DELAY_1                 (0x1D4 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_USE_RANK0_DELAYS_0                    (0x1D8 + DDR_PHY_BASE_ADDR)
#define    DATA1_REG_PHY_DLL_LOCK_DIFF_0                       (0x1DC + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_REG_STATUS_DLL_LOCK_0                     (0x1E0 + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_REG_STATUS_OF_IN_LOCK_STATE_0             (0x1E4 + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_REG_STATUS_OF_IN_DELAY_VALUE_0            (0x1E8 + DDR_PHY_BASE_ADDR)
#define    DATA1_PHY_REG_STATUS_OF_OUT_DELAY_VALUE_0           (0x1EC + DDR_PHY_BASE_ADDR)

//FIFO
#define FIFO_WE_OUT0_IO_CONFIG_I_0                             (0x338 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_OUT0_IO_CONFIG_SR_0                            (0x33C + DDR_PHY_BASE_ADDR)
#define FIFO_WE_OUT1_IO_CONFIG_I_0                             (0x340 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_OUT1_IO_CONFIG_SR_0                            (0x344 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_IN2_IO_CONFIG_I_0                              (0x348 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_IN2_IO_CONFIG_SR_0                             (0x34C + DDR_PHY_BASE_ADDR)
#define FIFO_WE_IN3_IO_CONFIG_I_0                              (0x350 + DDR_PHY_BASE_ADDR)
#define FIFO_WE_IN3_IO_CONFIG_SR_0                             (0x354 + DDR_PHY_BASE_ADDR)

//Leveling
#define DATA0_REG_PHY_WRLVL_NUM_OF_DQ0                         (0x35C + DDR_PHY_BASE_ADDR)
#define DATA0_REG_PHY_GATELVL_NUM_OF_DQ0                       (0x360 + DDR_PHY_BASE_ADDR)
#define DATA1_REG_PHY_WRLVL_NUM_OF_DQ0                         (0x364 + DDR_PHY_BASE_ADDR)
#define DATA1_REG_PHY_GATELVL_NUM_OF_DQ0                       (0x368 + DDR_PHY_BASE_ADDR)

//*******************************************************************
//Watchdog Timer registers
//*******************************************************************
#define    WDT1_BASE_ADDR                                        (0x44E35000)
#define    WDT1_WSPR                                             (WDT1_BASE_ADDR + 0x48)

//*****************************************************************************
//Read write prototype
//*****************************************************************************
#define WR_MEM_32(addr, data) *(unsigned int*)(addr) = (unsigned int)(data)
#define RD_MEM_32(addr)       *(unsigned int*)(addr)

//*****************************************************************************
//Global variables
//*****************************************************************************
UWORD32 CLKIN;


//*****************************************************************************
//Global Functions
//*****************************************************************************

//Watchdog is disabled to eliminate warm resets during debug
void Disable_Watchdog()
{
    WR_MEM_32(WDT1_WSPR,0x0000AAAA);
    WR_MEM_32(WDT1_WSPR,0x00005555);
}

//******************************************************************************
//System Initialization
//******************************************************************************

void AM335x_Beaglebone_Initialization()
    {
    //GEL_TextOut("****  AM335x Beaglebone Initialization is in progress .......... \n","Output",1,1,1);
    ARM_OPP100_Config();
    DDR2_EMIF_Config();
    //GEL_TextOut("****  AM335x Beaglebone Initialization is Done ****************** \n","Output",1,1,1);
    }

void GetInputClockFrequency()
{
    UWORD32 temp;

    temp = RD_MEM_32(CONTROL_STATUS) >> 22;
    temp = temp & 0x3;
    if (temp == 0)
    {
        CLKIN = 19;  //19.2MHz
        //GEL_TextOut("Input Clock Read from SYSBOOT[15:14]:  19.2MHz\n","Output",1,1,1);
    }
    if (temp == 1)
    {
        CLKIN = 24;  //24MHz
        //GEL_TextOut("Input Clock Read from SYSBOOT[15:14]:  24MHz\n","Output",1,1,1);
    }
    if (temp == 2)
    {
        CLKIN = 25;  //25MHz
        //GEL_TextOut("Input Clock Read from SYSBOOT[15:14]:  25MHz\n","Output",1,1,1);
    }
    if (temp == 3)
    {
        CLKIN = 26;  //26MHz
        //GEL_TextOut("Input Clock Read from SYSBOOT[15:14]:  26MHz\n","Output",1,1,1);
    }
}

void ARM_Turbo_Config()
{
unsigned int i;
//GEL_TextOut("************************************************************************ \n","Output",1,1,1);
//GEL_TextOut("****  NOTE:  VDD_MPU must be set to 1.26V for Turbo mode to work!!! **** \n","Output",1,1,1);
//GEL_TextOut("************************************************************************ \n","Output",1,1,1);
for(i=0;i<100000;i++);
//GEL_TextOut("****  AM335x ALL PLL Config for OPP == Turbo is in progress ......... \n","Output",1,1,1);
GetInputClockFrequency();
if(CLKIN==24)
{
   MPU_PLL_Config(  CLKIN, 23, 720, 1);
   CORE_PLL_Config( CLKIN, 23, 1000, 10, 8, 4);
   DDR_PLL_Config(  CLKIN, 23, 266, 1);
   PER_PLL_Config(  CLKIN, 23, 960, 5);
   DISP_PLL_Config( CLKIN, 23, 48, 1);
   //GEL_TextOut(" ****  AM335x ALL PLL Config for OPP == Turbo is done ......... \n","Output",1,1,1);
}
else {
   //GEL_TextOut("****  AM335x PLL Config failed!!  Check SYSBOOT[15:14] for proper input freq config \n","Output",1,1,1);
}
}

void ARM_OPP120_Config()
{
unsigned int i;
//GEL_TextOut("************************************************************************ \n","Output",1,1,1);
//GEL_TextOut("****  NOTE:  VDD_MPU must be set to 1.2V for OPP120 mode to work!!! **** \n","Output",1,1,1);
//GEL_TextOut("************************************************************************ \n","Output",1,1,1);
for(i=0;i<100000;i++);
//GEL_TextOut("****  AM335x ALL PLL Config for OPP == OPP120 is in progress ......... \n","Output",1,1,1);
GetInputClockFrequency();
if(CLKIN==24)
{
   MPU_PLL_Config(  CLKIN, 23, 650, 1);
   CORE_PLL_Config( CLKIN, 23, 1000, 10, 8, 4);
   DDR_PLL_Config(  CLKIN, 23, 266, 1);
   PER_PLL_Config(  CLKIN, 23, 960, 5);
   DISP_PLL_Config( CLKIN, 23, 48, 1);
   //GEL_TextOut(" ****  AM335x ALL ADPLL Config for OPP == OPP120 is done ......... \n","Output",1,1,1);
}
else {
   //GEL_TextOut("****  AM335x PLL Config failed!!  Check SYSBOOT[15:14] for proper input freq config \n","Output",1,1,1);
}
}

void ARM_OPP100_Config()
{
//GEL_TextOut("****  AM335x ALL PLL Config for OPP == OPP100 is in progress ......... \n","Output",1,1,1);
GetInputClockFrequency();
if(CLKIN==24)
{
   MPU_PLL_Config(  CLKIN, 23, 550, 1);
   CORE_PLL_Config( CLKIN, 23, 1000, 10, 8, 4);
   DDR_PLL_Config(  CLKIN, 23, 266, 1);
   PER_PLL_Config(  CLKIN, 23, 960, 5);
   DISP_PLL_Config( CLKIN, 23, 48, 1);
   //GEL_TextOut("****  AM335x ALL ADPLL Config for OPP == OPP100 is Done ......... \n","Output",1,1,1);
}
else {
   //GEL_TextOut("****  AM335x PLL Config failed!!  Check SYSBOOT[15:14] for proper input freq config \n","Output",1,1,1);
}
}

//**********************************************************************
//PLL Configuration functions
//**********************************************************************
void MPU_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2)
{
//UWORD32 ref_clk,clk_out = 0;
UWORD32 clkmode,clksel,div_m2;

//ref_clk     = CLKIN/(N+1);
//clk_out     = (ref_clk*M)/M2;

clkmode=RD_MEM_32(CM_CLKMODE_DPLL_MPU);
clksel= RD_MEM_32(CM_CLKSEL_DPLL_MPU);
div_m2= RD_MEM_32(CM_DIV_M2_DPLL_MPU);

//GEL_TextOut("****  Going to Bypass... \n","Output",1,1,1);

//put the DPLL in bypass mode
WR_MEM_32(CM_CLKMODE_DPLL_MPU,0x4);

while(((RD_MEM_32(CM_IDLEST_DPLL_MPU) & 0x101) != 0x00000100)); //wait for bypass status

//GEL_TextOut("****  Bypassed, changing values... \n","Output",1,1,1);

//set multiply and divide values
clksel = clksel & (~0x7FFFF);
clksel = clksel | ((M <<0x8) | N);
WR_MEM_32(CM_CLKSEL_DPLL_MPU,clksel);
div_m2 = div_m2 & ~0x1F;
div_m2 = div_m2 | M2;
WR_MEM_32(CM_DIV_M2_DPLL_MPU,div_m2);

//GEL_TextOut("****  Locking ARM PLL\n","Output",1,1,1);
//now lock the DPLL
clkmode = clkmode | 0x7;  //enables lock mode
WR_MEM_32(CM_CLKMODE_DPLL_MPU,clkmode);
while(((RD_MEM_32(CM_IDLEST_DPLL_MPU) & 0x101) != 0x1)); //wait for lock
}

void CORE_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M4,UWORD32 M5,UWORD32 M6)
{
//UWORD32 ref_clk,clk_out4,clk_out5,clk_out6;
UWORD32 clkmode,clksel,div_m4,div_m5,div_m6;

//ref_clk     = CLKIN/(N+1);
//clk_out4     = (ref_clk*M)/M4;  //M4=200MHz
//clk_out5     = (ref_clk*M)/M5;  //M5=250MHz
//clk_out6     = (ref_clk*M)/M6;  //M6=500MHz

clkmode=RD_MEM_32(CM_CLKMODE_DPLL_CORE);
clksel= RD_MEM_32(CM_CLKSEL_DPLL_CORE);
div_m4= RD_MEM_32(CM_DIV_M4_DPLL_CORE);
div_m5= RD_MEM_32(CM_DIV_M5_DPLL_CORE);
div_m6= RD_MEM_32(CM_DIV_M6_DPLL_CORE);

//put DPLL in bypass mode
clkmode = (clkmode & 0xfffffff8)|0x00000004;
WR_MEM_32(CM_CLKMODE_DPLL_CORE,clkmode);
while((RD_MEM_32(CM_IDLEST_DPLL_CORE) & 0x00000100 )!=0x00000100); //wait for bypass status

//GEL_TextOut("****  Core Bypassed\n","Output",1,1,1);

//set multiply and divide values
clksel = clksel & (~0x7FFFF);
clksel = clksel | ((M <<0x8) | N);
WR_MEM_32(CM_CLKSEL_DPLL_CORE,clksel);
div_m4= M4;   //200MHz
WR_MEM_32(CM_DIV_M4_DPLL_CORE,div_m4);
div_m5=  M5;  //250MHz
WR_MEM_32(CM_DIV_M5_DPLL_CORE,div_m5);
div_m6=  M6;  //500MHz
WR_MEM_32(CM_DIV_M6_DPLL_CORE,div_m6);

//GEL_TextOut("****  Now locking Core...\n","Output",1,1,1);

//now lock the PLL
clkmode =(clkmode&0xfffffff8)|0x00000007;
WR_MEM_32(CM_CLKMODE_DPLL_CORE,clkmode);

while((RD_MEM_32(CM_IDLEST_DPLL_CORE) & 0x00000001 )!=0x00000001);
//GEL_TextOut("****  Core locked\n","Output",1,1,1);
}

void DDR_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2)
{
//UWORD32 ref_clk,clk_out = 0;
UWORD32 clkmode,clksel,div_m2;

//ref_clk     = CLKIN/(N+1);
//clk_out     = (ref_clk*M)/M2;

clkmode=RD_MEM_32(CM_CLKMODE_DPLL_DDR);
clksel= RD_MEM_32(CM_CLKSEL_DPLL_DDR);
div_m2= RD_MEM_32(CM_DIV_M2_DPLL_DDR);

clkmode =(clkmode&0xfffffff8)|0x00000004;
WR_MEM_32(CM_CLKMODE_DPLL_DDR,clkmode);
while((RD_MEM_32(CM_IDLEST_DPLL_DDR) & 0x00000100 )!=0x00000100);

//GEL_TextOut("****  DDR DPLL Bypassed\n","Output",1,1,1);

clksel = clksel & (~0x7FFFF);
clksel = clksel | ((M <<0x8) | N);
WR_MEM_32(CM_CLKSEL_DPLL_DDR,clksel);
div_m2 = RD_MEM_32(CM_DIV_M2_DPLL_DDR);
div_m2 = (div_m2&0xFFFFFFE0) | M2;
WR_MEM_32(CM_DIV_M2_DPLL_DDR,div_m2);
clkmode =(clkmode&0xfffffff8)|0x00000007;
WR_MEM_32(CM_CLKMODE_DPLL_DDR,clkmode);


while((RD_MEM_32(CM_IDLEST_DPLL_DDR) & 0x00000001 )!=0x00000001);

//GEL_TextOut("****  DDR DPLL Locked\n","Output",1,1,1);
}

void PER_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2)
{
//UWORD32 ref_clk,clk_out = 0;
UWORD32 clkmode,clksel,div_m2;

//ref_clk     = CLKIN/(N+1);
//clk_out     = (ref_clk*M)/M2;

clkmode=RD_MEM_32(CM_CLKMODE_DPLL_PER);
clksel= RD_MEM_32(CM_CLKSEL_DPLL_PER);
div_m2= RD_MEM_32(CM_DIV_M2_DPLL_PER);

clkmode =(clkmode&0xfffffff8)|0x00000004;
WR_MEM_32(CM_CLKMODE_DPLL_PER,clkmode);
while((RD_MEM_32(CM_IDLEST_DPLL_PER) & 0x00000100 )!=0x00000100);

//GEL_TextOut("****  PER DPLL Bypassed\n","Output",1,1,1);

clksel = clksel & (~0x7FFFF);
clksel = clksel | ((M <<0x8) | N);
WR_MEM_32(CM_CLKSEL_DPLL_PER,clksel);
div_m2= 0xFFFFFF80 | M2;
WR_MEM_32(CM_DIV_M2_DPLL_PER,div_m2);
clkmode =(clkmode&0xfffffff8)|0x00000007;
WR_MEM_32(CM_CLKMODE_DPLL_PER,clkmode);

while((RD_MEM_32(CM_IDLEST_DPLL_PER) & 0x00000001 )!=0x00000001);

//GEL_TextOut("****  PER DPLL Locked\n","Output",1,1,1);
}

void DISP_PLL_Config(UWORD32 CLKIN,UWORD32 N,UWORD32 M,UWORD32 M2)
{
//UWORD32 ref_clk,clk_out = 0;
UWORD32 clkmode,clksel,div_m2;

//GEL_TextOut("****  DISP PLL Config is in progress .......... \n","Output",1,1,1);

//ref_clk     = CLKIN/(N+1);
//clk_out     = (ref_clk*M)/M2;

clkmode=RD_MEM_32(CM_CLKMODE_DPLL_DISP);
clksel= RD_MEM_32(CM_CLKSEL_DPLL_DISP);
div_m2= RD_MEM_32(CM_DIV_M2_DPLL_DISP);

clkmode =(clkmode&0xfffffff8)|0x00000004;
WR_MEM_32(CM_CLKMODE_DPLL_DISP,clkmode);
while((RD_MEM_32(CM_IDLEST_DPLL_DISP) & 0x00000100 )!=0x00000100);

clksel = clksel & (~0x7FFFF);
clksel = clksel | ((M <<0x8) | N);
WR_MEM_32(CM_CLKSEL_DPLL_DISP,clksel);
div_m2= 0xFFFFFFE0 | M2;
WR_MEM_32(CM_DIV_M2_DPLL_DISP,div_m2);
clkmode =(clkmode&0xfffffff8)|0x00000007;
WR_MEM_32(CM_CLKMODE_DPLL_DISP,clkmode);

while((RD_MEM_32(CM_IDLEST_DPLL_DISP) & 0x00000001 )!=0x00000001);

//GEL_TextOut("****  DISP PLL Config is DONE .......... \n","Output",1,1,1);
}


//##############################################################################
//##############################################################################
//                       DDR Configuration Section
//##############################################################################
//##############################################################################

//******************************************************************
//DDR2=266MHz
//OPP100
//******************************************************************

//*******************************************************************
//DDR2 PHY parameters
//*******************************************************************
#define  CMD_PHY_CTRL_SLAVE_RATIO        0x80
#define  CMD_PHY_INVERT_CLKOUT           0x0

#define  DATA_PHY_RD_DQS_SLAVE_RATIO     0x12
#define  DATA_PHY_FIFO_WE_SLAVE_RATIO    0x80  //RD_DQS_GATE
#define  DATA_PHY_WR_DQS_SLAVE_RATIO     0
#define  DATA_PHY_WR_DATA_SLAVE_RATIO    0x40  //WRITE_DATA

#define  DDR_IOCTRL_VALUE                (0x18B)

//******************************************************************
//EMIF parameters
//******************************************************************
#define DDR2_READ_LATENCY    0x05          //RD_Latency = (CL + 2) - 1
#define DDR2_SDRAM_TIMING1   0x0666B3C9
#define DDR2_SDRAM_TIMING2   0x243631CA
#define DDR2_SDRAM_TIMING3   0x00000337

#define DDR2_SDRAM_CONFIG    0x41805332		//termination = 1 (75ohm)
                                          //SDRAM drive = 0 (full)
                                          //CL = 4 (CAS latency = 4)
                                          //ROWSIZE = 6 (15 row bits)
                                          //PAGESIZE = 2 (10 column bits)
#define DDR2_REF_CTRL        0x0000081a   //266*7.8us = 2074.8 = 0x81A


void DDR2_EMIF_Config()
{
    //GEL_TextOut("****  AM335x DDR2 EMIF and PHY configuration is in progress... \n","Output",1,1,1);

    EMIF_PRCM_CLK_ENABLE();

    //GEL_TextOut("DDR PHY Configuration in progress \n","Output",1,1,1);

    VTP_Enable();

    PHY_Config_CMD();
    PHY_Config_DATA();

    //GEL_TextOut("Setting IO control registers....... \n","Output",1,1,1,i);
    WR_MEM_32(DDR_CMD0_IOCTRL,DDR_IOCTRL_VALUE);
    WR_MEM_32(DDR_CMD1_IOCTRL,DDR_IOCTRL_VALUE);
    WR_MEM_32(DDR_CMD2_IOCTRL,DDR_IOCTRL_VALUE);
    WR_MEM_32(DDR_DATA0_IOCTRL,DDR_IOCTRL_VALUE);
    WR_MEM_32(DDR_DATA1_IOCTRL,DDR_IOCTRL_VALUE);

    //IO to work for DDR2
    WR_MEM_32(DDR_IO_CTRL, RD_MEM_32(DDR_IO_CTRL) & ~0x10000000 );

    //CKE controlled by EMIF/DDR_PHY
    WR_MEM_32(DDR_CKE_CTRL, RD_MEM_32(DDR_CKE_CTRL) | 0x00000001);

    //GEL_TextOut("EMIF Timing register configuration is in progress ....... \n","Output",1,1,1);

    WR_MEM_32(EMIF_DDR_PHY_CTRL_1_REG, DDR2_READ_LATENCY);
    WR_MEM_32(EMIF_DDR_PHY_CTRL_1_SHDW_REG, DDR2_READ_LATENCY);
    WR_MEM_32(EMIF_DDR_PHY_CTRL_2_REG, DDR2_READ_LATENCY);

    WR_MEM_32(EMIF_SDRAM_TIM_1_REG,DDR2_SDRAM_TIMING1);
    WR_MEM_32(EMIF_SDRAM_TIM_1_SHDW_REG,DDR2_SDRAM_TIMING1);

    WR_MEM_32(EMIF_SDRAM_TIM_2_REG,DDR2_SDRAM_TIMING2);
    WR_MEM_32(EMIF_SDRAM_TIM_2_SHDW_REG,DDR2_SDRAM_TIMING2);

    WR_MEM_32(EMIF_SDRAM_TIM_3_REG,DDR2_SDRAM_TIMING3);
    WR_MEM_32(EMIF_SDRAM_TIM_3_SHDW_REG,DDR2_SDRAM_TIMING3);

    WR_MEM_32(EMIF_SDRAM_REF_CTRL_REG,DDR2_REF_CTRL);
    WR_MEM_32(EMIF_SDRAM_REF_CTRL_SHDW_REG,DDR2_REF_CTRL);

    WR_MEM_32(EMIF_SDRAM_CONFIG_REG, DDR2_SDRAM_CONFIG);

    //GEL_TextOut("EMIF Timing register configuration is done ....... \n","Output",1,1,1);

    if((RD_MEM_32(EMIF_STATUS_REG) & 0x4) == 0x4)
    {
        //GEL_TextOut("PHY is READY!!\n","Output",1,1,1);
    }

    //GEL_TextOut("DDR PHY Configuration done \n","Output",1,1,1);
}


void PHY_Config_CMD()
 	{
 	   UWORD32 i=0;
 	   for(i=0;i<3;i++)
	   {
          //GEL_TextOut("DDR PHY CMD%d Register configuration is in progress ....... \n","Output",1,1,1,i);

          WR_MEM_32(CMD0_REG_PHY_CTRL_SLAVE_RATIO_0 + (i*0x34),CMD_PHY_CTRL_SLAVE_RATIO);
          WR_MEM_32(CMD0_REG_PHY_INVERT_CLKOUT_0    + (i*0x34),CMD_PHY_INVERT_CLKOUT);
	   }
}

void PHY_Config_DATA()
{
	UWORD32 i;
	for(i=0;i<2;i++)
	{
        //GEL_TextOut("DDR PHY DATA%d Register configuration is in progress ....... \n","Output",1,1,1,i);

        WR_MEM_32(DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_0     + (i*0xA4),DATA_PHY_RD_DQS_SLAVE_RATIO);
        WR_MEM_32(DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_0     + (i*0xA4),DATA_PHY_WR_DQS_SLAVE_RATIO);
        WR_MEM_32(DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_0    + (i*0xA4),DATA_PHY_FIFO_WE_SLAVE_RATIO);
        WR_MEM_32(DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_0    + (i*0xA4),DATA_PHY_WR_DATA_SLAVE_RATIO);
	}
}

void EMIF_PRCM_CLK_ENABLE()
{
    //GEL_TextOut("EMIF PRCM is in progress ....... \n","Output",1,1,1);
    /* Enable EMIF4 Firewall clocks*/
    WR_MEM_32(CM_PER_EMIF_FW_CLKCTRL,0x02);
    /* Enable EMIF4 clocks*/
    WR_MEM_32(CM_PER_EMIF_CLKCTRL,0x02);
    /* Poll if module is functional */
    while(RD_MEM_32(CM_PER_EMIF_CLKCTRL)!= 0x02);
    //GEL_TextOut("EMIF PRCM Done \n","Output",1,1,1);
}

//************************************************************************
//VTP_Enable() routine                                                   *
//************************************************************************

void VTP_Enable()
{
      //Write 1 to enable VTP
      WR_MEM_32(VTP_CTRL_REG ,(RD_MEM_32(VTP_CTRL_REG) | 0x00000040));
      //Write 0 to CLRZ bit
      WR_MEM_32(VTP_CTRL_REG ,(RD_MEM_32(VTP_CTRL_REG) & 0xFFFFFFFE));
      //Write 1 to CLRZ bit
      WR_MEM_32(VTP_CTRL_REG ,(RD_MEM_32(VTP_CTRL_REG) | 0x00000001));
     //Check for VTP ready bit
      //GEL_TextOut("Waiting for VTP Ready ....... \n","Output",1,1,1);
      while((RD_MEM_32(VTP_CTRL_REG) & 0x00000020) != 0x00000020);
      //GEL_TextOut("VTP is Ready! \n","Output",1,1,1);
}

//##############################################################################
//##############################################################################
//                       SYS_CLKOUT2 Configuration Section
//##############################################################################
//##############################################################################

void OSC_32KHz()
{
set_CLKOUT2(0);
}

void L3_CLK()
{
set_CLKOUT2(1);
}

//DDR needs to be enabled
void DDR_PHY_Clock()
{
EMIF_PRCM_CLK_ENABLE();
set_CLKOUT2(2);
}

void PER_Clock()
{
set_CLKOUT2(3);
}

void LCD_Clock()
{
set_CLKOUT2(4);
}


void set_CLKOUT2(UWORD32 mode)
{
unsigned int temp;
unsigned int divider = 2; //change here if you want to pick a different divider

WR_MEM_32(CONF_XDMA_EVENT_INTR1,0x3); // Set Pinmux to mode 3 (and rest to zero)
WR_MEM_32(CM_CLKOUT_CTRL, (divider-1) << 3); //Set divider (which is set above)

temp = RD_MEM_32(CM_CLKOUT_CTRL);
temp = (temp & ~(0x7) ) | mode;
WR_MEM_32(CM_CLKOUT_CTRL,temp);

enable_SYS_CLKOUT2();

if(mode == 0) {
    //GEL_TextOut(" **** SYS_CLKOUT2 = 32khz Crystal (divided by %d)\n",,,,,(unsigned int *)(divider));
} else if (mode == 1) {
    //GEL_TextOut(" **** SYS_CLKOUT2 = L3 (From Core PLL) (divided by %d)\n",,,,,(unsigned int *)(divider));
} else if (mode == 2) {
    //GEL_TextOut(" **** SYS_CLKOUT2 = DDR PHY CLK (divided by %d)\n",,,,,(unsigned int *)(divider));
} else if (mode == 3) {
    //GEL_TextOut(" **** SYS_CLKOUT2 = Per PLL Clock (192 Mhz)(divided by %d)\n",,,,,(unsigned int *)(divider));
} else {
    //GEL_TextOut(" **** SYS_CLKOUT2 = LCD Pixel Clock (divided by %d)\n",,,,,(unsigned int *)(divider));
}
}

void enable_SYS_CLKOUT2()
{
unsigned int temp;
temp = RD_MEM_32(CM_CLKOUT_CTRL);
temp = temp | 0x80;
WR_MEM_32(CM_CLKOUT_CTRL,temp);
}


void Device_Type()
{
unsigned int temp;
temp = RD_MEM_32(CONTROL_STATUS);
temp = (temp & 0x700) >> 8;
if (temp == 0) {
  //GEL_TextOut(" **** Device Type: Test\n","Output",1,1,1);
} else if (temp == 1) {
  //GEL_TextOut(" **** Device Type: EMU\n","Output",1,1,1);
} else if (temp == 2) {
  //GEL_TextOut(" **** Device Type: HS\n","Output",1,1,1);
} else if (temp == 3) {
  //GEL_TextOut(" **** Device Type: GP\n","Output",1,1,1);
} else {
  //GEL_TextOut(" **** Device Type: INVALID\n","Output",1,1,1);
}
}
