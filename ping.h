/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:00:03 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/09 10:41:54 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PING_H
# define PING_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

#define PING_PKT_SIZE 64
#define PORT 0
#define PING_SLEEP_RATE 1000000
#define RECV_TIMEOUT 1

int	g_pingloop;

typedef	struct			s_ping
{
	struct			icmphdr	hdr;
	char			msg[PING_PKT_SIZE -sizeof(struct icmphdr)];
}				t_ping;

typedef	struct			s_main
{
	t_ping			pckt;
	int			ttl_val;
	char			*ip_addr;
	int			sockfd;
	int			msg_count;
	int			flag;
	int			addr_len;
	int			msg_received_count;
	struct sockaddr_in 	r_addr;
	struct timeval		time_start;
	struct timeval		time_end;
	struct timeval		tfs;
	struct timeval		tfe;
	long double		rtt_msec;
	long double		total_msec;
	struct timeval		tv_out;
}				t_main;
unsigned short			checksum(void *b, int len);
void				interupt_h(int inter);
char				*dns_lookup(char *addr_host, struct sockaddr_in *addr_con);
void				sec_sleep(int sec);
void				ping_help(int c, char **v);
void				exit_err(char *s);

#endif
