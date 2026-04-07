
xnap_return_et assign_hardcode_value_rrc_e2sm_kpm_ric_sub_req_t( rrc_e2sm_kpm_ric_sub_req_t *p_rrc_e2sm_kpm_ric_sub_req )
{
	    		p_rrc_e2sm_kpm_ric_sub_req->ric_request_id = 0;
	    		p_rrc_e2sm_kpm_ric_sub_req->ran_function_id = 0;
	    		p_rrc_e2sm_kpm_ric_sub_req->num_action = 2;
	    		p_rrc_e2sm_kpm_ric_sub_req->periodic = 0;
	    			p_rrc_e2sm_kpm_ric_sub_req->action_list[0].bitmask = 0;
	    			p_rrc_e2sm_kpm_ric_sub_req->action_list[0].report_period_ms = 0;
	    			p_rrc_e2sm_kpm_ric_sub_req->action_list[0].action_id = 0;
	    			p_rrc_e2sm_kpm_ric_sub_req->action_list[0].action_type = 0;
	    					p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.plmn_identity.presence_bitmask = 0;
	
	    				#if 1 /*idx24: mcc S */
	    					if (p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.plmn_identity.bitmask & PLMN_IDENTITY_MCC_PRESENCE_FLAG)
	    					{
		    					/* p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.plmn_identity.mcc is an array primitive, assigning fixed values */
	    					p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.plmn_identity.mcc = {0x01, 0x02}; /* example for octet string array */
	    					}
	    				#endif /* idx24: mcc E */
	
	    						p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.plmn_identity.mnc.count = 2;
	    						/* p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.plmn_identity.mnc.mnc is an array primitive, assigning variale values */
	    						p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.plmn_identity.mnc.mnc = {0x01, 0x02}; /* example for octet string array */
	    					p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.nr_cell_identity.numbits = 2;
	    					/* p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.nr_cell_identity.data is an array primitive, assigning variale values */
	    					p_rrc_e2sm_kpm_ric_sub_req->action_list[0].nr_cgi.nr_cell_identity.data = {0x01, 0x02}; /* example for octet string array */
	
	    		#if 1 /*idx38: report_mobility_req S */
	    			if (p_rrc_e2sm_kpm_ric_sub_req->action_list[0].bitmask & E2AP_REPORT_MOBILITY)
	    			{
		    				p_rrc_e2sm_kpm_ric_sub_req->action_list[0].report_mobility_req.is_ho_attempt = 0;
		    				p_rrc_e2sm_kpm_ric_sub_req->action_list[0].report_mobility_req.is_ho_succ = 0;
		    				p_rrc_e2sm_kpm_ric_sub_req->action_list[0].report_mobility_req.is_ho_failure = 0;
	    			}
	    		#endif /* idx38: report_mobility_req E */
	
	    			p_rrc_e2sm_kpm_ric_sub_req->action_list[1].bitmask = 0;
	    			p_rrc_e2sm_kpm_ric_sub_req->action_list[1].report_period_ms = 0;
	    			p_rrc_e2sm_kpm_ric_sub_req->action_list[1].action_id = 0;
	    			p_rrc_e2sm_kpm_ric_sub_req->action_list[1].action_type = 0;
	    					p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.plmn_identity.presence_bitmask = 0;
	
	    				#if 1 /*idx60: mcc S */
	    					if (p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.plmn_identity.bitmask & PLMN_IDENTITY_MCC_PRESENCE_FLAG)
	    					{
		    					/* p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.plmn_identity.mcc is an array primitive, assigning fixed values */
	    					p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.plmn_identity.mcc = {0x01, 0x02}; /* example for octet string array */
	    					}
	    				#endif /* idx60: mcc E */
	
	    						p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.plmn_identity.mnc.count = 2;
	    						/* p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.plmn_identity.mnc.mnc is an array primitive, assigning variale values */
	    						p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.plmn_identity.mnc.mnc = {0x01, 0x02}; /* example for octet string array */
	    					p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.nr_cell_identity.numbits = 2;
	    					/* p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.nr_cell_identity.data is an array primitive, assigning variale values */
	    					p_rrc_e2sm_kpm_ric_sub_req->action_list[1].nr_cgi.nr_cell_identity.data = {0x01, 0x02}; /* example for octet string array */
	
	    		#if 1 /*idx74: report_mobility_req S */
	    			if (p_rrc_e2sm_kpm_ric_sub_req->action_list[1].bitmask & E2AP_REPORT_MOBILITY)
	    			{
		    				p_rrc_e2sm_kpm_ric_sub_req->action_list[1].report_mobility_req.is_ho_attempt = 0;
		    				p_rrc_e2sm_kpm_ric_sub_req->action_list[1].report_mobility_req.is_ho_succ = 0;
		    				p_rrc_e2sm_kpm_ric_sub_req->action_list[1].report_mobility_req.is_ho_failure = 0;
	    			}
	    		#endif /* idx74: report_mobility_req E */
	
	    return XNAP_SUCCESS;
}
