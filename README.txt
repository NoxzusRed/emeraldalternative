Sospechosos en caso de romperse todo: (Cambios que hizo el ChatGPT que yo no pude entender pero que cumplían lo solicitado a la perfección)

---- Velocidad de las animaciones de combate----

src\battle_main.c

	void BattleMainCB2(void) (La función original está comentada encima de esa)

src\battle_controllers.c

	static void Controller_DoMoveAnimation(u32 battler) (No la función entera sino el fragmento que le sigue dentro de la función)
	
			if (gAnimScriptActive)
			gAnimScriptCallback();
	
include\config\battle.h

	#define B_MOVE_ANIM_SPEED (Configuración nueva que metió el chat para ajustar la velocidad de las animaciones en combate)