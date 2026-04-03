
#include <stdio.h>

void trace_device_config_t(device_config_t *p_device_config)
{
	    	fprintf(stderr, "\n[TRACE] ===== device_config_t =====\n");
	    	fprintf(stderr, "[TRACE] p_device_config->bitmask = %u\n", p_device_config->bitmask);
	    	fprintf(stderr, "[TRACE] p_device_config->version = %u\n", p_device_config->version);
	    	fprintf(stderr, "\n[TRACE] ===== rf_parameters_t =====\n");
	    	fprintf(stderr, "[TRACE] p_device_config->rf_params.bitmask = %u\n", p_device_config->rf_params.bitmask);
	    	fprintf(stderr, "[TRACE] p_device_config->rf_params.id = %u\n", p_device_config->rf_params.id);
	    	fprintf(stderr, "[TRACE] p_device_config->rf_params.num_bands = %u\n", p_device_config->rf_params.num_bands);
	    	for (int i = 0; i < MAX_BANDS; i++)
	    	{
		    		fprintf(stderr, "\n[TRACE] ===== band_parameters_t =====\n");
		    		fprintf(stderr, "[TRACE] p_device_config->rf_params.bands[i].bitmask = %u\n", p_device_config->rf_params.bands[i].bitmask);
		    		fprintf(stderr, "[TRACE] p_device_config->rf_params.bands[i].band_id = %u\n", p_device_config->rf_params.bands[i].band_id);
		    		fprintf(stderr, "[TRACE] p_device_config->rf_params.bands[i].frequency = %u\n", p_device_config->rf_params.bands[i].frequency);
		    		if (p_device_config->rf_params.bands[i].optional_param_id.bitmask & BAND_PARAM_BITMASK_OPTIONAL_PARAM_ID_PRESENT)
		    		{
			    			fprintf(stderr, "[TRACE] p_device_config->rf_params.bands[i].optional_param_id = %u\n", p_device_config->rf_params.bands[i].optional_param_id);
		    		}
		    		if (p_device_config->rf_params.bands[i].optional_param_data.bitmask & BAND_PARAM_BITMASK_OPTIONAL_PARAM_DATA_PRESENT)
		    		{
			    			fprintf(stderr, "[TRACE] p_device_config->rf_params.bands[i].optional_param_data = %u\n", p_device_config->rf_params.bands[i].optional_param_data);
		    		}
	    	}
	    	if (p_device_config->rf_params.config_blob.bitmask & RF_PARAM_BITMASK_CONFIG_BLOB_PRESENT)
	    	{
		    		for (int i = 0; i < 100; i++)
		    		{
			    			fprintf(stderr, "\n[TRACE] ===== octet_string_t =====\n");
			    			fprintf(stderr, "[TRACE] p_device_config->rf_params.config_blob[i].length_a = %u\n", p_device_config->rf_params.config_blob[i].length_a);
			    			fprintf(stderr, "[TRACE] p_device_config->rf_params.config_blob[i].data_a.length = %u\n", p_device_config->rf_params.config_blob[i].data_a.length);
			    			for (int i = 0; i < p_device_config->rf_params.config_blob[i].data_a.length; i++)
			    			{
				    				fprintf(stderr, "[TRACE] p_device_config->rf_params.config_blob[i].data_a.data[%d] = 0x%02X\n", i, p_device_config->rf_params.config_blob[i].data_a.data[i]);
			    			}
		    		}
	    	}
	    	if (p_device_config->extra_data_config.bitmask & CONFIG_PRESENT)
	    	{
		    		fprintf(stderr, "[TRACE] p_device_config->extra_data_config = %u\n", p_device_config->extra_data_config);
	    	}
	    	if (p_device_config->extra_data.bitmask & DEVICE_CONFIG_BITMASK_EXTRA_DATA_PRESENT)
	    	{
		    		for (int i = 0; i < 20; i++)
		    		{
			    			fprintf(stderr, "\n[TRACE] ===== octet_string_t =====\n");
			    			fprintf(stderr, "[TRACE] p_device_config->extra_data[i].length_a = %u\n", p_device_config->extra_data[i].length_a);
			    			fprintf(stderr, "[TRACE] p_device_config->extra_data[i].data_a.length = %u\n", p_device_config->extra_data[i].data_a.length);
			    			for (int i = 0; i < p_device_config->extra_data[i].data_a.length; i++)
			    			{
				    				fprintf(stderr, "[TRACE] p_device_config->extra_data[i].data_a.data[%d] = 0x%02X\n", i, p_device_config->extra_data[i].data_a.data[i]);
			    			}
		    		}
	    	}
	    	fprintf(stderr, "[TRACE] p_device_config->band_count = %u\n", p_device_config->band_count);
	    	for (int i = 0; i < 100; i++)
	    	{
		    		fprintf(stderr, "\n[TRACE] ===== band_parameters_t =====\n");
		    		fprintf(stderr, "[TRACE] p_device_config->band_data[i].bitmask = %u\n", p_device_config->band_data[i].bitmask);
		    		fprintf(stderr, "[TRACE] p_device_config->band_data[i].band_id = %u\n", p_device_config->band_data[i].band_id);
		    		fprintf(stderr, "[TRACE] p_device_config->band_data[i].frequency = %u\n", p_device_config->band_data[i].frequency);
		    		if (p_device_config->band_data[i].optional_param_id.bitmask & BAND_PARAM_BITMASK_OPTIONAL_PARAM_ID_PRESENT)
		    		{
			    			fprintf(stderr, "[TRACE] p_device_config->band_data[i].optional_param_id = %u\n", p_device_config->band_data[i].optional_param_id);
		    		}
		    		if (p_device_config->band_data[i].optional_param_data.bitmask & BAND_PARAM_BITMASK_OPTIONAL_PARAM_DATA_PRESENT)
		    		{
			    			fprintf(stderr, "[TRACE] p_device_config->band_data[i].optional_param_data = %u\n", p_device_config->band_data[i].optional_param_data);
		    		}
	    	}
	    	fprintf(stderr, "[TRACE] p_device_config->list_id.length = %u\n", p_device_config->list_id.length);
	    	for (int i = 0; i < p_device_config->list_id.length; i++)
	    	{
		    		fprintf(stderr, "[TRACE] p_device_config->list_id.data[%d] = 0x%02X\n", i, p_device_config->list_id.data[i]);
	    	}
	    	fprintf(stderr, "\n[TRACE] ===== plmn_id_t =====\n");
	    	fprintf(stderr, "[TRACE] p_device_config->plmn.plmn_count = %u\n", p_device_config->plmn.plmn_count);
	    	fprintf(stderr, "[TRACE] p_device_config->plmn.data.length = %u\n", p_device_config->plmn.data.length);
	    	for (int i = 0; i < p_device_config->plmn.data.length; i++)
	    	{
		    		fprintf(stderr, "[TRACE] p_device_config->plmn.data.data[%d] = 0x%02X\n", i, p_device_config->plmn.data.data[i]);
	    	}
}
