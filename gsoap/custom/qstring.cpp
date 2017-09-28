/*
        qstring.cpp

        See qstring.h for documentation.

        Compile this file and link it with your code.

gSOAP XML Web services tools
Copyright (C) 2000-2016, Robert van Engelen, Genivia Inc., All Rights Reserved.
This part of the software is released under ONE of the following licenses:
GPL, the gSOAP public license, OR Genivia's license for commercial use.
--------------------------------------------------------------------------------
gSOAP public license.

The contents of this file are subject to the gSOAP Public License Version 1.3
(the "License"); you may not use this file except in compliance with the
License. You may obtain a copy of the License at
http://www.cs.fsu.edu/~engelen/soaplicense.html
Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the License.

The Initial Developer of the Original Code is Robert A. van Engelen.
Copyright (C) 2000-2016, Robert van Engelen, Genivia, Inc., All Rights Reserved.
--------------------------------------------------------------------------------
GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

/* When using soapcpp2 option -q<name> or -p<name>, change "soapH.h" in the line below. */
/* soapH.h generated by soapcpp2 from .h file containing #import "qstring.h" */

#include "soapH.h"

void soap_serialize_xsd__string(struct soap *soap, QString const *a)
{
  (void)soap; (void)a; /* appease -Wall -Werror */
}

void soap_default_xsd__string(struct soap *soap, QString *a)
{
  (void)soap; /* appease -Wall -Werror */
  *a = QString::null;
}

int soap_out_xsd__string(struct soap *soap, char const *tag, int id, QString const *a, char const *type)
{
  if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, a, SOAP_TYPE_xsd__string), type)
   || soap_string_out(soap, soap_xsd__string2s(soap, *a), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}

QString *soap_in_xsd__string(struct soap *soap, char const *tag, QString *a, char const *type)
{
  if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
  if (*soap->type
   && soap_match_att(soap, soap->type, type)
   && soap_match_att(soap, soap->type, ":string"))
  {
    soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
  a = (QString*)soap_id_enter(soap, soap->id, a, SOAP_TYPE_xsd__string, sizeof(QString), NULL, NULL, NULL, NULL);
  if (*soap->href)
  {
    a = (QString*)soap_id_forward(soap, soap->href, a, 0, SOAP_TYPE_xsd__string, 0, sizeof(QString), 0, NULL, NULL);
  }
  else if (a)
  {
    if (soap_s2xsd__string(soap, soap_string_in(soap, 0, -1, -1, NULL), a))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return a;
}

const char * soap_xsd__string2s(struct soap *soap, QString a)
{
  QByteArray ba;
  if (soap->mode & SOAP_C_UTFSTRING)
    ba = a.toUtf8();
  else
    ba = a.toLatin1();
  size_t n = qstrlen(ba);
  char *s = (char*)soap_malloc(soap, n + 1);
  soap_strcpy(s, n + 1, ba.constData());
  return s;
}

int soap_s2xsd__string(struct soap *soap, const char *s, QString *a)
{
  *a = QString::null;
  if (s)
  {
    if (soap->mode & SOAP_C_UTFSTRING)
      *a = QString::fromUtf8(s, (int)strlen(s));
    else
      *a = QString::fromLatin1(s, (int)strlen(s));
  }
  return soap->error;
}