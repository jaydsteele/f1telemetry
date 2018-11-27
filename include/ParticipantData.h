#ifndef __ParticipantData_h__
#define __ParticipantData_h__

#include "include/types.h"
#include <cstring>
#include <iostream>

enum DriverID: uint8_t {
    CARLOS_SAINZ = 0, DANIEL_RICCIARDO = 2, FERNANDO_ALONSO = 3, KIMI_RÄIKKÖNEN = 6,
    LEWIS_HAMILTON = 7, MARCUS_ERICSSON = 8, MAX_VERSTAPPEN = 9, NICO_HULKENBURG = 10,
    KEVIN_MAGNUSSEN = 11, ROMAIN_GROSJEAN = 12, SEBASTIAN_VETTEL = 13, SERGIO_PEREZ = 14,
    VALTTERI_BOTTAS = 15, ESTEBAN_OCON = 17, STOFFEL_VANDOORNE = 18, LANCE_STROLL = 19,
    ARRON_BARNES = 20, MARTIN_GILES = 21, ALEX_MURRAY = 22, LUCAS_ROTH = 23,
    IGOR_CORREIA = 24, SOPHIE_LEVASSEUR = 25, JONAS_SCHIFFER = 26, ALAIN_FOREST = 27,
    JAY_LETOURNEAU = 28, ESTO_SAARI = 29, YASAR_ATIYEH = 30, CALLISTO_CALABRESI = 31,
    NAOTA_IZUM = 32, HOWARD_CLARKE = 33, WILHEIM_KAUFMANN = 34, MARIE_LAURSEN = 35,
    FLAVIO_NIEVES = 36, PETER_BELOUSOV = 37, KLIMEK_MICHALSKI = 38, SANTIAGO_MORENO = 39,
    BENJAMIN_COPPENS = 40, NOAH_VISSER = 41, GERT_WALDMULLER = 42, JULIAN_QUESADA = 43,
    DANIEL_JONES = 44, CHARLES_LECLERC = 58, PIERRE_GASLY = 59, BRENDON_HARTLEY = 60,
    SERGEY_SIROTKIN = 61, RUBEN_MEIJER = 69, RASHID_NAIR = 70, JACK_TREMBLAY = 71,
};
static const char * const DriverID_name[] = {
    "CARLOS_SAINZ", NULL, "DANIEL_RICCIARDO", "FERNANDO_ALONSO", NULL, NULL, "KIMI_RÄIKKÖNEN",
    "LEWIS_HAMILTON", "MARCUS_ERICSSON", "MAX_VERSTAPPEN", "NICO_HULKENBURG", "KEVIN_MAGNUSSEN",
    "ROMAIN_GROSJEAN", "SEBASTIAN_VETTEL", "SERGIO_PEREZ", "VALTTERI_BOTTAS", NULL,
    "ESTEBAN_OCON", "STOFFEL_VANDOORNE", "LANCE_STROLL", "ARRON_BARNES", "MARTIN_GILES",
    "ALEX_MURRAY", "LUCAS_ROTH", "IGOR_CORREIA", "SOPHIE_LEVASSEUR", "JONAS_SCHIFFER",
    "ALAIN_FOREST", "JAY_LETOURNEAU", "ESTO_SAARI", "YASAR_ATIYEH", "CALLISTO_CALABRESI",
    "NAOTA_IZUM", "HOWARD_CLARKE", "WILHEIM_KAUFMANN", "MARIE_LAURSEN", "FLAVIO_NIEVES",
    "PETER_BELOUSOV", "KLIMEK_MICHALSKI", "SANTIAGO_MORENO", "BENJAMIN_COPPENS", "NOAH_VISSER",
    "GERT_WALDMULLER", "JULIAN_QUESADA", "DANIEL_JONES", NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, "CHARLES_LECLERC", "PIERRE_GASLY",
    "BRENDON_HARTLEY", "SERGEY_SIROTKIN", NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    "RUBEN_MEIJER", "RASHID_NAIR", "JACK_TREMBLAY",
};

enum TeamID: uint8_t {
    MERCEDES = 0, FERRARI = 1, RED_BULL = 2, WILLIAMS = 3, FORCE_INDIA = 4, RENAULT = 5,
    TORO_ROSSO = 6, HAAS = 7, MCLAREN = 8, SAUBER = 9, MCLAREN_1988 = 10, MCLAREN_1991 = 11,
    WILLIAMS_1992 = 12, FERRARI_1995 = 13, WILLIAMS_1996 = 14, MCLAREN_1998 = 15, FERRARI_2002 = 16,
    FERRARI_2004 = 17, RENAULT_2006 = 18, FERRARI_2007 = 19, MCLAREN_2008 = 20, RED_BULL_2010 = 21,
    FERRARI_1976 = 22, MCLAREN_1976 = 23, LOTUS_1972 = 24, FERRARI_1979 = 25, MCLAREN_1982 = 26,
    WILLIAMS_2003 = 27, BRAWN_2009 = 28, LOTUS_1978 = 29,
};
static const char * const TeamID_name[] = {
    "MERCEDES", "FERRARI", "RED_BULL", "WILLIAMS", "FORCE_INDIA", "RENAULT", "TORO_ROSSO",
    "HAAS", "MCLAREN", "SAUBER", "MCLAREN_1988", "MCLAREN_1991", "WILLIAMS_1992", "FERRARI_1995",
    "WILLIAMS_1996", "MCLAREN_1998", "FERRARI_2002", "FERRARI_2004", "RENAULT_2006",
    "FERRARI_2007", "MCLAREN_2008", "RED_BULL_2010", "FERRARI_1976", "MCLAREN_1976",
    "LOTUS_1972", "FERRARI_1979", "MCLAREN_1982", "WILLIAMS_2003", "BRAWN_2009", "LOTUS_1978"
};

enum Nationality: uint8_t {
    AMERICAN = 1, ARGENTINEAN = 2, AUSTRALIAN = 3, AUSTRIAN = 4, AZERBAIJANI = 5,
    BAHRAINI = 6, BELGIAN = 7, BOLIVIAN = 8, BRAZILIAN = 9, BRITISH = 10,
    BULGARIAN = 11, CAMEROONIAN = 12, CANADIAN = 13, CHILEAN = 14, CHINESE = 15,
    COLOMBIAN = 16, COSTA_RICAN = 17, CROATIAN = 18, CYPRIOT = 19, CZECH = 20,
    DANISH = 21, DUTCH = 22, ECUADORIAN = 23, EMIRIAN = 24, ENGLISH = 25, ESTONIAN = 26,
    FINNISH = 27, FRENCH = 28, GERMAN = 29, GHANAIAN = 30, GREEK = 31, GUATEMALAN = 32,
    HONDURAN = 33, HONG_KONGER = 34, HUNGARIAN = 35, ICELANDER = 36, INDIAN = 37,
    INDONESIAN = 38, IRISH = 39, ISRAELI = 40, ITALIAN = 41, JAMAICAN = 42, JAPANESE = 43,
    JORDANIAN = 44, KUWAITI = 45, LATVIAN = 46, LEBANESE = 47, LITHUANIAN = 48, LUXEMBOURGER = 49,
    MALAYSIAN = 50, MALTESE = 51, MEXICAN = 52, MONEGASQUE = 53, NEW_ZEALANDER = 54,
    NICARAGUAN = 55, NORTH_KOREAN = 56, NORTHERN_IRISH = 57, NORWEGIAN = 58, OMANI = 59,
    PAKISTANI = 60, PANAMANIAN = 61, PARAGUAYAN = 62, PERUVIAN = 63, POLISH = 64,
    PORTUGUESE = 65, QATARI = 66, ROMANIAN = 67, RUSSIAN = 68, SALVADORAN = 69, SAUDI = 70,
    SCOTTISH = 71, SERBIAN = 72, SINGAPOREAN = 73, SLOVAKIAN = 74, SLOVENIAN = 75,
    SOUTH_AFRICAN = 76, SOUTH_KOREAN = 77, SPANISH = 78, SWEDISH = 79, SWISS = 80,
    TAIWANESE = 81, THAI = 82, TURKISH = 83, UKRAINIAN = 84, URUGUAYAN = 85, VENEZUELAN = 86,
    WELSH = 87
};
static const char * const Nationality_name[] = {
    "AMERICAN", "ARGENTINEAN", "AUSTRALIAN", "AUSTRIAN", "AZERBAIJANI", "BAHRAINI",
    "BELGIAN", "BOLIVIAN", "BRAZILIAN", "BRITISH", "BULGARIAN", "CAMEROONIAN", "CANADIAN",
    "CHILEAN", "CHINESE", "COLOMBIAN", "COSTA_RICAN", "CROATIAN", "CYPRIOT", "CZECH",
    "DANISH", "DUTCH", "ECUADORIAN", "EMIRIAN", "ENGLISH", "ESTONIAN", "FINNISH",
    "FRENCH", "GERMAN", "GHANAIAN", "GREEK", "GUATEMALAN", "HONDURAN", "HONG_KONGER",
    "HUNGARIAN", "ICELANDER", "INDIAN", "INDONESIAN", "IRISH", "ISRAELI", "ITALIAN",
    "JAMAICAN", "JAPANESE", "JORDANIAN", "KUWAITI", "LATVIAN", "LEBANESE", "LITHUANIAN",
    "LUXEMBOURGER", "MALAYSIAN", "MALTESE", "MEXICAN", "MONEGASQUE", "NEW_ZEALANDER",
    "NICARAGUAN", "NORTH_KOREAN", "NORTHERN_IRISH", "NORWEGIAN", "OMANI", "PAKISTANI",
    "PANAMANIAN", "PARAGUAYAN", "PERUVIAN", "POLISH", "PORTUGUESE", "QATARI", "ROMANIAN",
    "RUSSIAN", "SALVADORAN", "SAUDI", "SCOTTISH", "SERBIAN", "SINGAPOREAN", "SLOVAKIAN",
    "SLOVENIAN", "SOUTH_AFRICAN", "SOUTH_KOREAN", "SPANISH", "SWEDISH", "SWISS",
    "TAIWANESE", "THAI", "TURKISH", "UKRAINIAN", "URUGUAYAN", "VENEZUELAN", "WELSH"
};

struct ParticipantData
{
    static const int BUFFER_SIZE = 53;

    uint8_t    m_aiControlled;           // Whether the vehicle is AI (1) or Human (0) controlled
    uint8_t    m_driverId;               // Driver id - see appendix
    uint8_t    m_teamId;                 // Team id - see appendix
    uint8_t    m_raceNumber;             // Race number of the car
    uint8_t    m_nationality;            // Nationality of the driver
    char       m_name[48];               // Name of participant in UTF-8 format – null terminated
                                         // Will be truncated with … (U+2026) if too long

    wchar_t    m_name_w[24];             // wide character version of m_name

    friend std::istream& operator >>(std::istream& is, ParticipantData& data) {
        static char buffer[BUFFER_SIZE];
        is.read(buffer, sizeof(buffer));
        if (is.good()) {
            int pos = 0;
            data.m_aiControlled = unpack_uint8(buffer, pos);
            data.m_driverId = unpack_uint8(buffer, pos+=1);
            data.m_teamId = unpack_uint8(buffer, pos+=1);
            data.m_raceNumber = unpack_uint8(buffer, pos+=1);
            data.m_nationality = unpack_uint8(buffer, pos+=1);
            memcpy(data.m_name, &buffer[pos+=1], 48);
            std::mbstowcs(data.m_name_w, &buffer[pos], 24);
        }
        return is;
    }

    void dump(std::wostream& os, int indent=0) {
        wchar_t wm_name[24];
        std::mbstowcs(wm_name, this->m_name, 24);
        os << whitespace(indent) << "ParticipantData {" << std::endl;
        os << whitespace(indent) << "  m_aiControlled: " << (int)this->m_aiControlled << std::endl;
        os << whitespace(indent) << "  m_driverId: " << (int)this->m_driverId << std::endl;
        os << whitespace(indent) << "  m_teamId: " << (int)this->m_teamId << std::endl;
        os << whitespace(indent) << "  m_raceNumber: " << (int)this->m_raceNumber << std::endl;
        os << whitespace(indent) << "  m_nationality: " << (int)this->m_nationality << std::endl;
        os << whitespace(indent) << "  m_name: " << this->m_name_w << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif