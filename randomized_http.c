#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <curl/curl.h>

int random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

char* random_user_agent() {
    static char* user_agents[] = {
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36",
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Firefox/54.0",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.12; rv:54.0) Gecko/20100101 Firefox/54.0",
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:55.0) Gecko/20100101 Firefox/55.0",
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64; Trident/7.0; AS; rv:11.0) like Gecko"
    };
    return user_agents[random_number(0, 4)];
}

char* random_referer() {
    static char* referers[] = {
        "https://www.google.com/",
        "https://www.facebook.com/",
        "https://www.twitter.com/",
        "https://www.linkedin.com/",
        "https://www.instagram.com/"
    };
    return referers[random_number(0, 4)];
}

char* random_accept_language() {
    static char* languages[] = {
        "en-US,en;q=0.9",
        "th-TH,th;q=0.9",
        "en-GB,en;q=0.8",
        "de-DE,de;q=0.7",
        "fr-FR,fr;q=0.6"
    };
    return languages[random_number(0, 4)];
}

char* random_accept() {
    static char* accepts[] = {
        "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
        "application/json,text/plain,*/*;q=0.5",
        "text/css,*/*;q=0.1",
        "image/png,image/svg+xml,*/*;q=0.9"
    };
    return accepts[random_number(0, 3)];
}

char* random_connection() {
    static char* connections[] = {
        "keep-alive",
        "close"
    };
    return connections[random_number(0, 1)];
}

char* random_query_parameter() {
    static char* params[] = {
        "?utm_source=google",
        "?utm_medium=social",
        "?utm_campaign=promo",
        "?ref=homepage",
        "?ref=search",
        ""
    };
    return params[random_number(0, 5)];
}

void send_request(const char* base_url) {
    CURL *curl;
    CURLcode res;
    char final_url[256];

    snprintf(final_url, sizeof(final_url), "%s%s", base_url, random_query_parameter());

    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *headers = NULL;

        headers = curl_slist_append(headers, "Accept-Encoding: gzip, deflate, br");
        headers = curl_slist_append(headers, "Connection: keep-alive");

        char header_buffer[256];
        
        snprintf(header_buffer, sizeof(header_buffer), "User-Agent: %s", random_user_agent());
        headers = curl_slist_append(headers, header_buffer);
        
        snprintf(header_buffer, sizeof(header_buffer), "Referer: %s", random_referer());
        headers = curl_slist_append(headers, header_buffer);

        snprintf(header_buffer, sizeof(header_buffer), "Accept-Language: %s", random_accept_language());
        headers = curl_slist_append(headers, header_buffer);

        snprintf(header_buffer, sizeof(header_buffer), "Accept: %s", random_accept());
        headers = curl_slist_append(headers, header_buffer);

        curl_easy_setopt(curl, CURLOPT_URL, final_url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Request successful with URL: %s\n", final_url);
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
}

int main() {
    srand(time(NULL));

    const char* url = "https://th.shp.ee/4lly4dh?smtt=0.0.9";

    while (1) {
        send_request(url);
    }

    return 0;
}