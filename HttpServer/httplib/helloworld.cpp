#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>

#define SERVER_CERT_FILE "./cert.pem"
#define SERVER_PRIVATE_KEY_FILE "./key.pem"

#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
  httplib::SSLServer svr(SERVER_CERT_FILE, SERVER_PRIVATE_KEY_FILE);
#else
  httplib::Server svr;
#endif

if (!svr.is_valid()) {
printf("server has an error...\n");
return -1;
}

svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
  res.set_content("Hello World!", "text/plain");
});

svr.listen("0.0.0.0", 8080);