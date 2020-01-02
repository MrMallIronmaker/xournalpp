#include "XojPdfDocument.h"

#include <config-features.h>

#include "pdf/popplerapi/PopplerGlibDocument.h"

XojPdfDocument::XojPdfDocument(): doc(new PopplerGlibDocument()) {}

XojPdfDocument::XojPdfDocument(const XojPdfDocument& doc): doc(new PopplerGlibDocument()) {}

XojPdfDocument::~XojPdfDocument() {
    delete doc;
    doc = nullptr;
}

auto XojPdfDocument::operator=(const XojPdfDocument& doc) -> XojPdfDocument& {
    this->doc->assign(doc.doc);
    return *this;
}

auto XojPdfDocument::operator==(XojPdfDocument& doc) -> bool { return this->doc->equals(doc.doc); }

void XojPdfDocument::assign(XojPdfDocumentInterface* doc) { this->doc->assign(doc); }

auto XojPdfDocument::equals(XojPdfDocumentInterface* doc) -> bool { return this->doc->equals(doc); }

auto XojPdfDocument::save(Path filename, GError** error) -> bool { return doc->save(filename, error); }

auto XojPdfDocument::load(Path filename, string password, GError** error) -> bool {
    return doc->load(filename, password, error);
}

auto XojPdfDocument::load(gpointer data, gsize length, string password, GError** error) -> bool {
    return doc->load(data, length, password, error);
}

auto XojPdfDocument::isLoaded() -> bool { return doc->isLoaded(); }

auto XojPdfDocument::getPage(size_t page) -> XojPdfPageSPtr { return doc->getPage(page); }

auto XojPdfDocument::getPageCount() -> size_t { return doc->getPageCount(); }

auto XojPdfDocument::getDocumentInterface() -> XojPdfDocumentInterface* { return doc; }

auto XojPdfDocument::getContentsIter() -> XojPdfBookmarkIterator* { return doc->getContentsIter(); }
