/* $Id$ */

/*
 * Copyright (c) 2006,2007,2008
 *               Eino Tuominen <eino@utu.fi>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef CONF_H
#define CONF_H

#define DEFAULT_CONFIG	"update",		"grey", 	\
			"host",			"127.0.0.1",	\
			"port",			"5525",		\
			"sync_port",		"5524",		\
			"status_port",		"5522",		\
			"rotate_interval", 	"3600",		\
			"filter_bits",		"24",		\
			"number_buffers",	"8",            \
			"stat_interval",	"300",		\
			"postfix_response_grey","action=defer_if_permit %reason%", \
			"postfix_response_block","action=reject %reason%",	\
			"sjsms_response_grey",	"$X4.4.3|$N%reason%", \
			"sjsms_response_match",	"$Y", 		\
			"sjsms_response_trust",	"$Y",		\
			"sjsms_response_block", "$N%reason%",	\
			"log_method",		"syslog",	\
			"log_level",		"info",		\
			"stat_type",		"delay",	\
			"stat_type",		"status",	\
			"grey_mask",		"24",		\
			"grey_delay",		"10",           \
			"grey_tuple",		"user",		\
			"syslog_facility",	"mail",		\
			"blocker_port",		"4466",		\
			"blocker_weight",	"1",		\
			"block_threshold",	"0",		\
			"grey_threshold",	"1",		\
			"grey_reason",		"Please try again later", \
			"block_reason",		"Bad reputation", \
			"query_timelimit",	"5000",		\
			"pool_maxthreads",	"100"

#define MULTIVALUES	"dnsbl",	\
			"rhsbl",	\
			"dnswl",	\
			"check",	\
                        "stat_type",	\
			"protocol", 	\
			"log_method"

#define VALID_NAMES     "dnsbl",			\
			"rhsbl",			\
			"dnswl",			\
			"host",				\
			"port",				\
                        "filter_bits",			\
                        "rotate_interval",		\
                        "number_buffers",		\
                        "update",			\
                        "peer_name",			\
                        "statefile",			\
			"postfix_response_grey",	\
			"postfix_response_block",	\
			"sjsms_response_grey",		\
			"sjsms_response_match",		\
			"sjsms_response_trust",		\
			"sjsms_response_block",		\
                        "log_method",			\
                        "log_level",			\
			"grey_mask",			\
                        "grey_delay",               	\
                        "grey_tuple",               	\
			"check",			\
			"protocol",			\
                        "syslog_facility",		\
                        "sync_listen",			\
                        "sync_peer",			\
                        "sync_port",			\
                        "stat_interval",		\
                        "stat_type",			\
			"status",			\
			"blocker_host",			\
			"blocker_port",			\
			"blocker_weight",		\
			"query_timelimit",		\
			"block_threshold",		\
			"grey_threshold",		\
			"grey_reason",			\
			"block_reason",			\
			"milter_listen",		\
			"pidfile",			\
			"pool_maxthreads"

#define DEPRECATED_NAMES 	"syncport",		\
				"synchost",		\
				"peerport",		\
				"peerhost",		\
				"statushost",		\
				"statusport"


#define RUNTIME_MODIFIABLE	"grey_threshold",		\
				"block_threshold",		\
				"pool_maxthreads",		\
				"grey_mask",			\
				"grey_delay",			\
				"log_level",			\
				"check",			\
				"query_timelimit",		\
				"postfix_response_grey",        \
				"postfix_response_block",       \
				"sjsms_response_grey",          \
				"sjsms_response_match",         \
				"sjsms_response_trust",         \
				"sjsms_response_block",         \
				"grey_reason", 		        \
				"block_reason", 	        \
				"update"
/*
 * How many parameters a given keyword accepts, format is
 * "keyword", MIN, MAX. -1 as maximum means unlimited
 */
#define PARAMS	"dnsbl",	"0",	"1",	\
		"rhsbl",	"0",	"1",	\
		"pidfile",	"0",	"1"

typedef struct params_s
{
	const char *value;
	struct params_s *next;	/* linked list */
} params_t;

typedef struct configlist_s
{
	bool is_default;
	const char *name;
	const char *value;
	params_t *params;
	struct configlist_s *next;	/* linked list */
} configlist_t;

configlist_t *default_config(void);
int read_config(configlist_t **config, const char *filename);
const char *gconf(configlist_t *config, const char *name);

#endif /* CONF_H */
