
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void increase_counters(void);

void _CYCLIC ProgramCyclic(void)
{
	URTK(&URTK1);
	
	increase_counters();
	
	URTKView_0 .InstRef = URTK1.InstRef;
	
	URTKView(&URTKView_0 );
	
	urtk_out.internal_axisZ1 = URTK1.internal_axisZ1 + 252.315;
	urtk_out.internal_axisZ2 = URTK1.internal_axisZ2 + 336.641;
	urtk_out.internal_axisZ3 = URTK1.internal_axisZ3-50.1246;
	urtk_out.internal_axisY1 = URTK1.internal_axisY1 + 280.678;
	urtk_out.internal_axisY2 = URTK1.internal_axisY2 + 114.875;
	urtk_out.internal_axisY3 = URTK1.internal_axisY3 - 267.531;
	urtk_out.internal_Ground1 = URTK1.internal_Ground1 + 241.35;
	urtk_out.internal_Ground2 = URTK1.internal_Ground2 + 20.735;
	urtk_out.internal_Ground3 = URTK1.internal_Ground3 - 50.4717;
	urtk_out.internal_movementX1 = URTK1.internal_movementX1 + 253.027;
	urtk_out.internal_movementX2 = URTK1.internal_movementX2 + 38.0305;
	urtk_out.internal_movementX3 = URTK1.internal_movementX3 - 49.6654;
	urtk_out.internal_movementY1 = URTK1.internal_movementY1 + 281.057;
	urtk_out.internal_movementY2 = URTK1.internal_movementY2 + 116.335;
	urtk_out.internal_movementY3 = URTK1.internal_movementY3 - 48;
	urtk_out.internal_movementZ1 = URTK1.internal_movementZ1 + 252.937;
	urtk_out.internal_movementZ2 = URTK1.internal_movementZ2 + 117;
	urtk_out.internal_movementZ3 = URTK1.internal_movementZ3 - 48.6654;
	
	
	

	
	
	
	
	
	if (urtk_out.internal_movementX1 <= 80)
	{
		sensorX1 = 1;
	}
	
	if (urtk_out.internal_movementX1 >= 340)
	{
		sensorX2 = 1;
	}
	
	if (urtk_out.internal_movementX1 >= 80 && urtk_out.internal_movementX1 <= 340)
	{
		sensorX1 = 0;
		sensorX2 = 0;
	}
	
	if (urtk_out.internal_movementZ2 <= 130)
	{
		sensorY1 = 1;
	}
	
	if (urtk_out.internal_movementZ2 >= 390)
	{
		sensorY2 = 1;
	}
	
	if (urtk_out.internal_movementZ2 >= 130 && urtk_out.internal_movementZ2 <= 390)
	{
		sensorY1 = 0;
		sensorY2 = 0;
	}
	
	if (urtk_out.internal_axisY3 <= -255)
	{
		sensorZ1 = 1;
	}
	
	if (urtk_out.internal_axisY3 >= 10)
	{
		sensorZ2 = 1;
	}
	
	if (urtk_out.internal_axisY3 >= -255 && urtk_out.internal_axisY3 <= 10)
	{
		sensorZ1 = 0;
		sensorZ2 = 0;
	}
	
	Axis_X_EncIf.iActTime = (INT)	AsIOTimeCyclicStart();
	Axis_X_EncIf.iActPos = urtk_out.internal_movementX1*100;
	Axis_X_DiDoIf.iPosHwEnd = sensorX2;
	Axis_X_DiDoIf.iNegHwEnd = sensorX1;
	URTK1.Xinputvelocity = Axis_X_DrvIf.oSetPos * 1000.0 / 32767;
	
	
	
	/*
	
	if (urtk_out.internal_movementX1 <= 80)
	{
		sensorX1 = 1;
		if (URTK1.Xinputvelocity > 0)
			URTK1.Xinputvelocity = 0;
	}
	
	if (urtk_out.internal_movementX1 >= 340)
	{
		sensorX2 = 1;
		if (URTK1.Xinputvelocity < 0)
			URTK1.Xinputvelocity = 0;
	}
	
	if (urtk_out.internal_movementX1 >= 80 && urtk_out.internal_movementX1 <= 340)
	{
		sensorX1 = 0;
		sensorX2 = 0;
	}
	
	if (urtk_out.internal_movementZ2 <= 130)
	{
		sensorY1 = 1;
		if (URTK1.Zimputevelocity < 0)
			URTK1.Zimputevelocity = 0;
	}
	
	if (urtk_out.internal_movementZ2 >= 390)
	{
		sensorY2 = 1;
		if (URTK1.Zimputevelocity > 0)
			URTK1.Zimputevelocity = 0;
	}
	
	if (urtk_out.internal_movementZ2 >= 130 && urtk_out.internal_movementZ2 <= 390)
	{
		sensorY1 = 0;
		sensorY2 = 0;
	}
	
	if (urtk_out.internal_axisY3 <= -255)
	{
		sensorZ1 = 1;
		if (URTK1.Yimputvelocity < 0)
			URTK1.Yimputvelocity = 0;
	}
	
	if (urtk_out.internal_axisY3 >= 10)
	{
		sensorZ2 = 1;
		if (URTK1.Yimputvelocity > 0)
			URTK1.Yimputvelocity = 0;
	}
	
	if (urtk_out.internal_axisY3 >= -255 && urtk_out.internal_axisY3 <= 10)
	{
		sensorZ1 = 0;
		sensorZ2 = 0;
	}
	
	int max_speed = 1000;
	
	if (URTK1.Xinputvelocity>max_speed)
		URTK1.Xinputvelocity = max_speed;
	if (URTK1.Xinputvelocity<-max_speed)
		URTK1.Xinputvelocity = -max_speed;
		
	if (URTK1.Zimputevelocity>max_speed)
		URTK1.Zimputevelocity = max_speed;
	if (URTK1.Zimputevelocity<-max_speed)
		URTK1.Zimputevelocity = -max_speed;
		
	if (URTK1.Yimputvelocity>max_speed)
		URTK1.Yimputvelocity = max_speed;
	if (URTK1.Yimputvelocity<-max_speed)
		URTK1.Yimputvelocity = -max_speed;
	
	
	*/
		
}

void increase_counters(void)
{
	Axis_X_EncIf.iLifeCnt++;
	Axis_X_DiDoIf.iLifeCntDriveEnable++; 
	Axis_X_DiDoIf.iLifeCntDriveReady++; 
	Axis_X_DiDoIf.iLifeCntNegHwEnd++; 
	Axis_X_DiDoIf.iLifeCntPosHwEnd++; 
	Axis_X_DiDoIf.iLifeCntReference++;
	Axis_X_DrvIf.iLifeCnt++;
}