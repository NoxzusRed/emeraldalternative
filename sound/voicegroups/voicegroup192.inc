	.align 2
voicegroup192::
	@ A small GBA sample kit for Wally's GM drum pitches (36-57).
	@ Reuse the game's own DirectSound samples, without duplicating data.
	voice_directsound_no_resample 60, 64, DirectSoundWaveData_sc88pro_rnd_kick, 255, 0, 255, 242
	voice_directsound_no_resample 60, 64, DirectSoundWaveData_sc88pro_rnd_snare, 255, 0, 255, 242
	voice_directsound_no_resample 60, 79, DirectSoundWaveData_unknown_close_hihat, 255, 127, 0, 188
	voice_directsound_no_resample 60, 79, DirectSoundWaveData_unknown_open_hihat, 255, 242, 141, 0
	voice_directsound_no_resample 30, 54, DirectSoundWaveData_sc88pro_orchestra_cymbal_crash, 255, 246, 0, 216
	voice_directsound_no_resample 60, 14, DirectSoundWaveData_trinity_cymbal_crash, 255, 235, 0, 165
