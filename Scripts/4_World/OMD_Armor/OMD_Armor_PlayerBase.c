modded class PlayerBase
{
	protected static const int OMD_Armor_RPC_PLATE_FX = 4782107;

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (rpc_type != OMD_Armor_RPC_PLATE_FX)
		{
			return;
		}

		if (GetGame().IsDedicatedServer())
		{
			return;
		}

		OMD_Armor_ReadPlateFx(ctx);
	}

	protected void OMD_Armor_ReadPlateFx(ParamsReadContext ctx)
	{
		vector worldPos;
		vector dir;
		string result;
		string fxType;
		bool ok;
		bool wantSound;
		bool wantSparks;
		float sparkOffset;
		wantSound = true;
		wantSparks = true;
		sparkOffset = 0.1;
		worldPos = "0 0 0";
		dir = "0 0 1";
		result = "";
		fxType = "";
		ok = ctx.Read(worldPos);
		if (!ok)
		{
			return;
		}

		ok = ctx.Read(dir);
		if (!ok)
		{
			return;
		}

		ok = ctx.Read(result);
		if (!ok)
		{
			return;
		}

		ok = ctx.Read(fxType);
		if (!ok)
		{
			return;
		}

		ok = ctx.Read(wantSound);
		if (!ok)
		{
			return;
		}

		ok = ctx.Read(wantSparks);
		if (!ok)
		{
			return;
		}

		ok = ctx.Read(sparkOffset);
		if (!ok)
		{
			return;
		}

		OMD_Armor_PlayPlateFx(worldPos, dir, result, fxType, wantSound, wantSparks, sparkOffset);
	}

	protected void OMD_Armor_PlayPlateFx(vector worldPos, vector dir, string result, string fxType, bool wantSound, bool wantSparks, float sparkOffset)
	{
		string fxCheck;
		vector sparkPos;
		vector back;
		if (GetGame().IsDedicatedServer())
		{
			return;
		}

		fxCheck = fxType;
		fxCheck.ToLower();
		if (fxCheck != "metal")
		{
			return;
		}

		back = dir * sparkOffset;
		sparkPos = worldPos - back;
		if (wantSparks)
		{
			if (result == "STOP")
			{
				OMD_Armor_PlayPlateStop(sparkPos, dir);
			}

			if (result == "PEN")
			{
				OMD_Armor_PlayPlatePen(sparkPos, dir);
			}
		}

		if (!wantSound)
		{
			return;
		}

		if (result == "STOP" || result == "PEN")
		{
			OMD_Armor_PlayPlateSound(worldPos);
		}
	}

	protected void OMD_Armor_PlayPlateStop(vector worldPos, vector dir)
	{
		Hit_Metal eff;
		vector inSpeed;
		vector outSpeed;
		vector normal;
		vector exitPos;
		string ammoName;
		eff = new Hit_Metal();
		inSpeed = dir * 700;
		outSpeed = "0 0 0";
		normal = dir * -1;
		exitPos = worldPos;
		ammoName = "Bullet_762x39";
		if (normal == "0 0 0")
		{
			normal = "0 1 0";
		}

		eff.EvaluateEffect(this, 0, worldPos, ImpactTypes.STOP, normal, exitPos, inSpeed, outSpeed, ammoName);
		eff.SetAutodestroy(true);
		SEffectManager.PlayInWorld(eff, worldPos);
	}

	protected void OMD_Armor_PlayPlatePen(vector worldPos, vector dir)
	{
		Hit_Metal eff;
		vector inSpeed;
		vector outSpeed;
		vector normal;
		vector exitPos;
		vector step;
		string ammoName;
		float len;
		eff = new Hit_Metal();
		outSpeed = dir;
		len = outSpeed.Length();
		if (len <= 0.001)
		{
			outSpeed = "0 0 1";
		}

		inSpeed = outSpeed * 700;
		normal = outSpeed * -1;
		outSpeed = outSpeed * 300;
		if (normal == "0 0 0")
		{
			normal = "0 1 0";
		}

		step = dir * 0.3;
		exitPos = worldPos + step;
		ammoName = "Bullet_762x39";
		eff.EvaluateEffect(this, 0, worldPos, ImpactTypes.PENETRATE, normal, exitPos, inSpeed, outSpeed, ammoName);
		eff.SetAutodestroy(true);
		SEffectManager.PlayInWorld(eff, worldPos);
	}

	protected void OMD_Armor_PlayPlateSound(vector worldPos)
	{
		EffectSound sound;
		sound = SEffectManager.PlaySoundEnviroment("OMD_Armor_PlateHit_SoundSet", worldPos);
		if (sound)
		{
			sound.SetAutodestroy(true);
		}
	}
};
