/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:59:50 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/18 11:00:07 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ping.h>

void		sec_sleep(int sec)
{
	struct timeval current;
	struct timeval next;

	gettimeofday(&current, NULL);
	next = current;
	next.tv_sec += sec;
	while (current.tv_sec < next.tv_sec ||
		current.tv_usec < next.tv_usec)
	{
		gettimeofday(&current, NULL);
	}
}

unsigned short checksum(void *b, int len)
{
	unsigned short *buf;
	unsigned int	sum;

	buf = b;
	sum = 0;
	while (len > 1)
	{
		sum += *buf++;
		len -= 2;
	}
	if (len == 1)
		sum += *(unsigned char *)buf;
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	return ((unsigned short)~sum);
}

void		interupt_h(int inter)
{
	g_pingloop = 0;
	(void)inter;
}

char		*dns_lookup(char *addr_host, struct sockaddr_in *addr_con)
{
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct sockaddr_in	*sa_in;
	char			*ip;

	memset(&(hints), 0, sizeof(hints));
	hints.ai_family = AF_INET;
	if ((ip = malloc(INET_ADDRSTRLEN)) < 0)
		printf("Error malloc");
	if (getaddrinfo(addr_host, NULL, &hints, &(res)) < 0)
		printf("ping: unknown host\n");
	sa_in = (struct sockaddr_in *)res->ai_addr;
	inet_ntop(res->ai_family, &(sa_in->sin_addr), ip, INET_ADDRSTRLEN);
	(*addr_con) = *sa_in;
	(*addr_con).sin_port = htons (PORT);
	return (ip);
}

