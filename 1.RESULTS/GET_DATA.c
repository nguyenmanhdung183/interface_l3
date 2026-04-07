
#include <stdio.h>

void trace_rrc_e2sm_kpm_ric_sub_req_t(rrc_e2sm_kpm_ric_sub_req_t *p_rrc_e2sm_kpm_ric_sub_req)
{
	    	fprintf(stderr, "\n[TRACE] ===== rrc_e2sm_kpm_ric_sub_req_t =====\n");
	    	fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->ric_request_id = %u\n", p_rrc_e2sm_kpm_ric_sub_req->ric_request_id);
	    	fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->ran_function_id = %u\n", p_rrc_e2sm_kpm_ric_sub_req->ran_function_id);
	    	fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->num_action = %u\n", p_rrc_e2sm_kpm_ric_sub_req->num_action);
	    	fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->periodic = %u\n", p_rrc_e2sm_kpm_ric_sub_req->periodic);
	    	for (int i = 0; i < num_action; i++)
	    	{
		    		fprintf(stderr, "\n[TRACE] ===== e2ap_ric_action_list_t =====\n");
		    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].bitmask = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].bitmask);
		    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].report_period_ms = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].report_period_ms);
		    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].action_id = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].action_id);
		    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].action_type = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].action_type);
		    		fprintf(stderr, "\n[TRACE] ===== rrc_ncgi_t =====\n");
		    		fprintf(stderr, "\n[TRACE] ===== rrc_plmn_identity_t =====\n");
		    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.presence_bitmask = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.presence_bitmask);
		    		/* p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mcc is an array primitive, fixed length */
		    		for (int i = 0; i < p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mcc.; i++)
		    		{
			    			fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mcc.[%d] = 0x%02X\n", i, p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mcc.data[i]);
		    		}
		    		fprintf(stderr, "\n[TRACE] ===== rrc_mnc_t =====\n");
		    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mnc.count = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mnc.count);
		    		/* p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mnc.mnc is an array primitive, variable length */
		    		for (int i = 0; i < p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mnc.mnc; i++)
		    		{
			    			fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mnc.mnc[%d] = 0x%02X\n", i, p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.plmn_identity.mnc.mnc.data[i]);
		    		}
		    		fprintf(stderr, "\n[TRACE] ===== rrc_nr_cell_identity_t =====\n");
		    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.nr_cell_identity.numbits = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.nr_cell_identity.numbits);
		    		/* p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.nr_cell_identity.data is an array primitive, variable length */
		    		for (int i = 0; i < p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.nr_cell_identity.data; i++)
		    		{
			    			fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.nr_cell_identity.data[%d] = 0x%02X\n", i, p_rrc_e2sm_kpm_ric_sub_req->action_list[i].nr_cgi.nr_cell_identity.data.data[i]);
		    		}
		
		    		if (p_rrc_e2sm_kpm_ric_sub_req->action_list[i].bitmask & E2AP_REPORT_MOBILITY)
		    		{
			    		fprintf(stderr, "\n[TRACE] ===== e2_report_mobility_req_t =====\n");
			    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].report_mobility_req.is_ho_attempt = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].report_mobility_req.is_ho_attempt);
			    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].report_mobility_req.is_ho_succ = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].report_mobility_req.is_ho_succ);
			    		fprintf(stderr, "[TRACE] p_rrc_e2sm_kpm_ric_sub_req->action_list[i].report_mobility_req.is_ho_failure = %u\n", p_rrc_e2sm_kpm_ric_sub_req->action_list[i].report_mobility_req.is_ho_failure);
		    		}
	    	}
}
