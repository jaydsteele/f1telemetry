#ifndef __ParticipantData_h__
#define __ParticipantData_h__

#include "types.h"
#include "utils.h"
#include <cstring>
#include <iostream>

enum DriverID: uint8_t {
    DRIVER_ID_CARLOS_SAINZ = 0,
    // EMPTY = 1,
    DRIVER_ID_DANIEL_RICCIARDO = 2,
    DRIVER_ID_FERNANDO_ALONSO = 3,
    // EMPTY = 4,
    // EMPTY = 5,
    DRIVER_ID_KIMI_RÄIKKÖNEN = 6,
    DRIVER_ID_LEWIS_HAMILTON = 7,
    DRIVER_ID_MARCUS_ERICSSON = 8,
    DRIVER_ID_MAX_VERSTAPPEN = 9,
    DRIVER_ID_NICO_HULKENBURG = 10,
    DRIVER_ID_KEVIN_MAGNUSSEN = 11,
    DRIVER_ID_ROMAIN_GROSJEAN = 12,
    DRIVER_ID_SEBASTIAN_VETTEL = 13,
    DRIVER_ID_SERGIO_PEREZ = 14,
    DRIVER_ID_VALTTERI_BOTTAS = 15,
    // EMPTY = 16,
    DRIVER_ID_ESTEBAN_OCON = 17,
    DRIVER_ID_STOFFEL_VANDOORNE = 18,
    DRIVER_ID_LANCE_STROLL = 19,
    DRIVER_ID_ARRON_BARNES = 20,
    DRIVER_ID_MARTIN_GILES = 21,
    DRIVER_ID_ALEX_MURRAY = 22,
    DRIVER_ID_LUCAS_ROTH = 23,
    DRIVER_ID_IGOR_CORREIA = 24,
    DRIVER_ID_SOPHIE_LEVASSEUR = 25,
    DRIVER_ID_JONAS_SCHIFFER = 26,
    DRIVER_ID_ALAIN_FOREST = 27,
    DRIVER_ID_JAY_LETOURNEAU = 28,
    DRIVER_ID_ESTO_SAARI = 29,
    DRIVER_ID_YASAR_ATIYEH = 30,
    DRIVER_ID_CALLISTO_CALABRESI = 31,
    DRIVER_ID_NAOTA_IZUM = 32,
    DRIVER_ID_HOWARD_CLARKE = 33,
    DRIVER_ID_WILHEIM_KAUFMANN = 34,
    DRIVER_ID_MARIE_LAURSEN = 35,
    DRIVER_ID_FLAVIO_NIEVES = 36,
    DRIVER_ID_PETER_BELOUSOV = 37,
    DRIVER_ID_KLIMEK_MICHALSKI = 38,
    DRIVER_ID_SANTIAGO_MORENO = 39,
    DRIVER_ID_BENJAMIN_COPPENS = 40,
    DRIVER_ID_NOAH_VISSER = 41,
    DRIVER_ID_GERT_WALDMULLER = 42,
    DRIVER_ID_JULIAN_QUESADA = 43,
    DRIVER_ID_DANIEL_JONES = 44,
    // EMPTY = 45,
    // EMPTY = 46,
    // EMPTY = 47,
    // EMPTY = 48,
    // EMPTY = 49,
    // EMPTY = 50,
    // EMPTY = 51,
    // EMPTY = 52,
    // EMPTY = 53,
    // EMPTY = 54,
    // EMPTY = 55,
    // EMPTY = 56,
    // EMPTY = 57,
    DRIVER_ID_CHARLES_LECLERC = 58,
    DRIVER_ID_PIERRE_GASLY = 59,
    DRIVER_ID_BRENDON_HARTLEY = 60,
    DRIVER_ID_SERGEY_SIROTKIN = 61,
    // EMPTY = 62,
    // EMPTY = 63,
    // EMPTY = 64,
    // EMPTY = 65,
    // EMPTY = 66,
    // EMPTY = 67,
    // EMPTY = 68,
    DRIVER_ID_RUBEN_MEIJER = 69,
    DRIVER_ID_RASHID_NAIR = 70,
    DRIVER_ID_JACK_TREMBLAY = 71,
};
static const char * const DriverID_name[] = {
    "CARLOS_SAINZ", NULL, "DANIEL_RICCIARDO", "FERNANDO_ALONSO", NULL, NULL, "KIMI_RAIKKONEN",
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
    TEAM_ID_MERCEDES = 0,
    TEAM_ID_FERRARI = 1,
    TEAM_ID_RED_BULL = 2,
    TEAM_ID_WILLIAMS = 3,
    TEAM_ID_FORCE_INDIA = 4,
    TEAM_ID_RENAULT = 5,
    TEAM_ID_TORO_ROSSO = 6,
    TEAM_ID_HAAS = 7,
    TEAM_ID_MCLAREN = 8,
    TEAM_ID_SAUBER = 9,
    TEAM_ID_MCLAREN_1988 = 10,
    TEAM_ID_MCLAREN_1991 = 11,
    TEAM_ID_WILLIAMS_1992 = 12,
    TEAM_ID_FERRARI_1995 = 13,
    TEAM_ID_WILLIAMS_1996 = 14,
    TEAM_ID_MCLAREN_1998 = 15,
    TEAM_ID_FERRARI_2002 = 16,
    TEAM_ID_FERRARI_2004 = 17,
    TEAM_ID_RENAULT_2006 = 18,
    TEAM_ID_FERRARI_2007 = 19,
    TEAM_ID_MCLAREN_2008 = 20,
    TEAM_ID_RED_BULL_2010 = 21,
    TEAM_ID_FERRARI_1976 = 22,
    TEAM_ID_MCLAREN_1976 = 23,
    TEAM_ID_LOTUS_1972 = 24,
    TEAM_ID_FERRARI_1979 = 25,
    TEAM_ID_MCLAREN_1982 = 26,
    TEAM_ID_WILLIAMS_2003 = 27,
    TEAM_ID_BRAWN_2009 = 28,
    TEAM_ID_LOTUS_1978 = 29,
};
static const char
* const TeamID_name[]
= {
    "MERCEDES", "FERRARI", "RED_BULL", "WILLIAMS", "FORCE_INDIA", "RENAULT", "TORO_ROSSO",
    "HAAS", "MCLAREN", "SAUBER", "MCLAREN_1988", "MCLAREN_1991", "WILLIAMS_1992", "FERRARI_1995",
    "WILLIAMS_1996", "MCLAREN_1998", "FERRARI_2002", "FERRARI_2004", "RENAULT_2006",
    "FERRARI_2007", "MCLAREN_2008", "RED_BULL_2010", "FERRARI_1976", "MCLAREN_1976",
    "LOTUS_1972", "FERRARI_1979", "MCLAREN_1982", "WILLIAMS_2003", "BRAWN_2009", "LOTUS_1978"
};

enum Nationality: uint8_t {
    NATIONALITY_AMERICAN = 1,
    NATIONALITY_ARGENTINEAN = 2,
    NATIONALITY_AUSTRALIAN = 3,
    NATIONALITY_AUSTRIAN = 4,
    NATIONALITY_AZERBAIJANI = 5,
    NATIONALITY_BAHRAINI = 6,
    NATIONALITY_BELGIAN = 7,
    NATIONALITY_BOLIVIAN = 8,
    NATIONALITY_BRAZILIAN = 9,
    NATIONALITY_BRITISH = 10,
    NATIONALITY_BULGARIAN = 11,
    NATIONALITY_CAMEROONIAN = 12,
    NATIONALITY_CANADIAN = 13,
    NATIONALITY_CHILEAN = 14,
    NATIONALITY_CHINESE = 15,
    NATIONALITY_COLOMBIAN = 16,
    NATIONALITY_COSTA_RICAN = 17,
    NATIONALITY_CROATIAN = 18,
    NATIONALITY_CYPRIOT = 19,
    NATIONALITY_CZECH = 20,
    NATIONALITY_DANISH = 21,
    NATIONALITY_DUTCH = 22,
    NATIONALITY_ECUADORIAN = 23,
    NATIONALITY_EMIRIAN = 24,
    NATIONALITY_ENGLISH = 25,
    NATIONALITY_ESTONIAN = 26,
    NATIONALITY_FINNISH = 27,
    NATIONALITY_FRENCH = 28,
    NATIONALITY_GERMAN = 29,
    NATIONALITY_GHANAIAN = 30,
    NATIONALITY_GREEK = 31,
    NATIONALITY_GUATEMALAN = 32,
    NATIONALITY_HONDURAN = 33,
    NATIONALITY_HONG_KONGER = 34,
    NATIONALITY_HUNGARIAN = 35,
    NATIONALITY_ICELANDER = 36,
    NATIONALITY_INDIAN = 37,
    NATIONALITY_INDONESIAN = 38,
    NATIONALITY_IRISH = 39,
    NATIONALITY_ISRAELI = 40,
    NATIONALITY_ITALIAN = 41,
    NATIONALITY_JAMAICAN = 42,
    NATIONALITY_JAPANESE = 43,
    NATIONALITY_JORDANIAN = 44,
    NATIONALITY_KUWAITI = 45,
    NATIONALITY_LATVIAN = 46,
    NATIONALITY_LEBANESE = 47,
    NATIONALITY_LITHUANIAN = 48,
    NATIONALITY_LUXEMBOURGER = 49,
    NATIONALITY_MALAYSIAN = 50,
    NATIONALITY_MALTESE = 51,
    NATIONALITY_MEXICAN = 52,
    NATIONALITY_MONEGASQUE = 53,
    NATIONALITY_NEW_ZEALANDER = 54,
    NATIONALITY_NICARAGUAN = 55,
    NATIONALITY_NORTH_KOREAN = 56,
    NATIONALITY_NORTHERN_IRISH = 57,
    NATIONALITY_NORWEGIAN = 58,
    NATIONALITY_OMANI = 59,
    NATIONALITY_PAKISTANI = 60,
    NATIONALITY_PANAMANIAN = 61,
    NATIONALITY_PARAGUAYAN = 62,
    NATIONALITY_PERUVIAN = 63,
    NATIONALITY_POLISH = 64,
    NATIONALITY_PORTUGUESE = 65,
    NATIONALITY_QATARI = 66,
    NATIONALITY_ROMANIAN = 67,
    NATIONALITY_RUSSIAN = 68,
    NATIONALITY_SALVADORAN = 69,
    NATIONALITY_SAUDI = 70,
    NATIONALITY_SCOTTISH = 71,
    NATIONALITY_SERBIAN = 72,
    NATIONALITY_SINGAPOREAN = 73,
    NATIONALITY_SLOVAKIAN = 74,
    NATIONALITY_SLOVENIAN = 75,
    NATIONALITY_SOUTH_AFRICAN = 76,
    NATIONALITY_SOUTH_KOREAN = 77,
    NATIONALITY_SPANISH = 78,
    NATIONALITY_SWEDISH = 79,
    NATIONALITY_SWISS = 80,
    NATIONALITY_TAIWANESE = 81,
    NATIONALITY_THAI = 82,
    NATIONALITY_TURKISH = 83,
    NATIONALITY_UKRAINIAN = 84,
    NATIONALITY_URUGUAYAN = 85,
    NATIONALITY_VENEZUELAN = 86,
    NATIONALITY_WELSH = 87
};
static const char * const Nationality_name[] = {
    NULL, "AMERICAN", "ARGENTINEAN", "AUSTRALIAN", "AUSTRIAN", "AZERBAIJANI", "BAHRAINI",
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

    wchar_t    m_name_w[24];             // wide character duplicate of m_name

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
        os << whitespace(indent) << "  m_driverId: " << DriverID_name[this->m_driverId] << std::endl;
        os << whitespace(indent) << "  m_teamId: " << TeamID_name[this->m_teamId] << std::endl;
        os << whitespace(indent) << "  m_raceNumber: " << (int)this->m_raceNumber << std::endl;
        os << whitespace(indent) << "  m_nationality: " << Nationality_name[this->m_nationality] << std::endl;
        os << whitespace(indent) << "  m_name: " << this->m_name_w << std::endl;
        os << whitespace(indent) << "}" << std::endl;
    }

};

#endif