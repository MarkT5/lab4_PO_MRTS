
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif


void _INIT ProgramInit(void)
{	
	urtk_out.internal_axisZ1 = 252.315;
	urtk_out.internal_axisZ2 = 336.641;
	urtk_out.internal_axisZ3 = -50.1246;
	urtk_out.internal_axisY1 = 280.678;
	urtk_out.internal_axisY2 = 114.875;
	urtk_out.internal_axisY3 = -267.531;
	urtk_out.internal_Ground1 = 241.35;
	urtk_out.internal_Ground2 = 20.735;
	urtk_out.internal_Ground3 = -50.4717;
	urtk_out.internal_movementX1 = 253.027;
	urtk_out.internal_movementX2 = 38.0305;
	urtk_out.internal_movementX3 = -49.6654;
	urtk_out.internal_movementY1 = 281.057;
	urtk_out.internal_movementY2 = 116.335;
	urtk_out.internal_movementY3 = -48;
	urtk_out.internal_movementZ1 = 252.937;
	urtk_out.internal_movementZ2 = 117;
	urtk_out.internal_movementZ3 = -48.6654;
	
	/*
	// Инициализация двигателей и регуляторов
	fb_motor_x.ke = 0;
	fb_motor_x.Tm = 0;
	
	fb_motor_y.ke = 0;
	fb_motor_y.Tm = 0;
	
	fb_motor_z.ke = 0;
	fb_motor_z.Tm = 0;
	
	fb_controller.k_i = 0;
	fb_controller.k_p = 0;
	fb_controller.max_abs_value = 24;
	*/
	//SDC Типы
	Axis_X_HW.EncIf1_Typ = ncSDC_ENC16;
	Axis_X_HW.DiDoIf_Typ = ncSDC_DIDO;
	Axis_X_HW.DrvIf_Typ = ncSDC_DRVSERVO16;
	
	//Устанавливаем имена переменных
	strcpy(Axis_X_HW.EncIf1_Name, "Axis_X_EncIf");
	strcpy(Axis_X_HW.DrvIf_Name, "Axis_X_DrvIf");
	strcpy(Axis_X_HW.DiDoIf_Name, "Axis_X_DiDoIf");
		
	//Устанавливаем входы готовности и нормальной работы
	Axis_X_EncIf.iEncOK = 1;
	Axis_X_DrvIf.iDrvOK = 1;
	Axis_X_DrvIf.iStatusEnable = 1;
	Axis_X_DiDoIf.iDriveReady = 1;
	
}
