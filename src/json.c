/*
 * transmission-remote-gtk - A GTK RPC client to Transmission
 * Copyright (C) 2011  Alan Fitton

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <glib-object.h>
#include <glib/gprintf.h>
#include <json-glib/json-glib.h>
#include <gtk/gtk.h>

#include "config.h"
#include "protocol-constants.h"
#include "requests.h"
#include "dispatch.h"
#include "http.h"
#include "json.h"

gchar *trg_serialize(JsonNode * req)
{
    JsonGenerator *generator;
    gsize length;
    gchar *response;

    generator = json_generator_new();
    json_generator_set_root(generator, req);

    response = json_generator_to_data(generator, &length);
    g_object_unref(generator);

    return response;
}

JsonObject *trg_deserialize(struct http_response * response,
                            GError ** error)
{
    JsonParser *parser;
    JsonNode *root;
    JsonObject *ret = NULL;

    parser = json_parser_new();
    json_parser_load_from_data(parser, response->data, response->size,
                               error);
    if (*error == NULL) {
        root = json_parser_get_root(parser);
#ifdef DEBUG
        if (g_getenv("TRG_SHOW_INCOMING") != NULL) {
            g_printf("incoming JSON data:\n%s\n", response->data);
        } else if (g_getenv("TRG_SHOW_INCOMING_PRETTY") != NULL) {
            JsonGenerator *pg;
            gsize len;
            gchar *pgdata;

            pg = json_generator_new();
            g_object_set(pg, "pretty", TRUE, NULL);
            json_generator_set_root(pg, root);

            pgdata = json_generator_to_data(pg, &len);
            g_printf("incoming JSON data:\n%s\n", pgdata);
            g_free(pgdata);

            g_object_unref(pg);
        }
#endif
        ret = json_node_get_object(root);
        json_object_ref(ret);
    }

    g_object_unref(parser);
    return ret;
}

JsonObject *node_get_arguments(JsonNode * req)
{
    JsonObject *rootObj = json_node_get_object(req);
    return get_arguments(rootObj);
}

JsonObject *get_arguments(JsonObject * req)
{
    return json_object_get_object_member(req, PARAM_ARGUMENTS);
}
