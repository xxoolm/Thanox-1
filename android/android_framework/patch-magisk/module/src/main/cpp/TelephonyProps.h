//
// Created by Tornaco on 7/7/21.
//

#ifndef THANOX_INTERNAL_TELEPHONYPROPS_H
#define THANOX_INTERNAL_TELEPHONYPROPS_H

//****** Baseband and Radio Interface version
/**
 * Baseband version
 * Availability: property is available any time radio is on
 */
#define PROPERTY_BASEBAND_VERSION "gsm.version.baseband"

/** Radio Interface Layer (RIL) library implementation. */
#define PROPERTY_RIL_IMPL "gsm.version.ril-impl"

//****** Current Network

/** Alpha name of current registered operator.<p>
 *  Availability: when registered to a network. Result may be unreliable on
 *  CDMA networks.
 */
#define PROPERTY_OPERATOR_ALPHA "gsm.operator.alpha"
//TODO: most of these properties are generic, substitute gsm. with phone. bug 1856959

/** Numeric name (MCC+MNC) of current registered operator.<p>
 *  Availability: when registered to a network. Result may be unreliable on
 *  CDMA networks.
 */
#define PROPERTY_OPERATOR_NUMERIC "gsm.operator.numeric"

/** 'true' if the device is on a manually selected network
 *
 *  Availability: when registered to a network
 */
#define PROPERTY_OPERATOR_ISMANUAL "operator.ismanual"

/** 'true' if the device is considered roaming on this network for GSM
 *  purposes.
 *  Availability: when registered to a network
 */
#define PROPERTY_OPERATOR_ISROAMING "gsm.operator.isroaming"

/** The ISO country code equivalent of the current registered operator's
 *  MCC (Mobile Country Code)<p>
 *  Availability: when registered to a network. Result may be unreliable on
 *  CDMA networks.
 */
#define PROPERTY_OPERATOR_ISO_COUNTRY "gsm.operator.iso-country"

/**
 * The contents of this property is the value of the kernel command line
 * product_type variable that corresponds to a product that supports LTE on CDMA.
 * {@see BaseCommands#getLteOnCdmaMode()}
 */
#define PROPERTY_LTE_ON_CDMA_PRODUCT_TYPE "telephony.lteOnCdmaProductType"

/**
 * The contents of this property is the one of {@link Phone#LTE_ON_CDMA_TRUE} or
 * {@link Phone#LTE_ON_CDMA_FALSE}. If absent the value will assumed to be false
 * and the {@see #PROPERTY_LTE_ON_CDMA_PRODUCT_TYPE} will be used to determine its
 * final value which could also be {@link Phone#LTE_ON_CDMA_FALSE}.
 * {@see BaseCommands#getLteOnCdmaMode()}
 */
#define PROPERTY_LTE_ON_CDMA_DEVICE "telephony.lteOnCdmaDevice"

#define CURRENT_ACTIVE_PHONE "gsm.current.phone-type"

//****** SIM Card
/**
 * One of <code>"UNKNOWN"</code> <code>"ABSENT"</code> <code>"PIN_REQUIRED"</code>
 * <code>"PUK_REQUIRED"</code> <code>"NETWORK_LOCKED"</code> or <code>"READY"</code>
 */
#define PROPERTY_SIM_STATE "gsm.sim.state"

/** The MCC+MNC (mobile country code+mobile network code) of the
 *  provider of the SIM. 5 or 6 decimal digits.
 *  Availability: SIM state must be "READY"
 */
#define PROPERTY_ICC_OPERATOR_NUMERIC "gsm.sim.operator.numeric"

/** PROPERTY_ICC_OPERATOR_ALPHA is also known as the SPN, or Service Provider Name.
 *  Availability: SIM state must be "READY"
 */
#define PROPERTY_ICC_OPERATOR_ALPHA "gsm.sim.operator.alpha"

/** ISO country code equivalent for the SIM provider's country code*/
#define PROPERTY_ICC_OPERATOR_ISO_COUNTRY "gsm.sim.operator.iso-country"

/**
 * Indicates the available radio technology.  Values include: <code>"unknown"</code>,
 * <code>"GPRS"</code>, <code>"EDGE"</code> and <code>"UMTS"</code>.
 */
#define PROPERTY_DATA_NETWORK_TYPE "gsm.network.type"

/** Indicate if phone is in emergency callback mode */
#define PROPERTY_INECM_MODE "ril.cdma.inecmmode"

/** Indicate the timer value for exiting emergency callback mode */
#define PROPERTY_ECM_EXIT_TIMER "ro.cdma.ecmexittimer"

/** the international dialing prefix of current operator network */
#define PROPERTY_OPERATOR_IDP_STRING "gsm.operator.idpstring"

/**
 * Defines the schema for the carrier specified OTASP number
 */
#define PROPERTY_OTASP_NUM_SCHEMA "ro.cdma.otaspnumschema"

/**
 * Disable all calls including Emergency call when it set to true.
 */
#define PROPERTY_DISABLE_CALL "ro.telephony.disable-call"

/**
 * Set to true for vendor RIL's that send multiple UNSOL_CALL_RING notifications.
 */
#define PROPERTY_RIL_SENDS_MULTIPLE_CALL_RING ="ro.telephony.call_ring.multiple"

/**
 * The number of milliseconds between CALL_RING notifications.
 */
#define PROPERTY_CALL_RING_DELAY "ro.telephony.call_ring.delay"

/**
 * Track CDMA SMS message id numbers to ensure they increment
 * monotonically, regardless of reboots.
 */
#define PROPERTY_CDMA_MSG_ID "persist.radio.cdma.msgid"

/**
 * Property to override DEFAULT_WAKE_LOCK_TIMEOUT
 */
#define PROPERTY_WAKE_LOCK_TIMEOUT "ro.ril.wake_lock_timeout"

/**
 * Set to true to indicate that the modem needs to be reset
 * when there is a radio technology change.
 */
#define PROPERTY_RESET_ON_RADIO_TECH_CHANGE "persist.radio.reset_on_switch"

/**
 * Set to false to disable SMS receiving, default is
 * the value of config_sms_capable
 */
#define PROPERTY_SMS_RECEIVE "telephony.sms.receive"

/**
 * Set to false to disable SMS sending, default is
 * the value of config_sms_capable
 */
#define PROPERTY_SMS_SEND "telephony.sms.send"

/**
 * Set to true to indicate a test CSIM card is used in the device.
 * This property is for testing purpose only. This should not be defined
 * in commercial configuration.
 */
#define PROPERTY_TEST_CSIM "persist.radio.test-csim"

/**
 * Ignore RIL_UNSOL_NITZ_TIME_RECEIVED completely, used for debugging/testing.
 */
#define PROPERTY_IGNORE_NITZ "telephony.test.ignore.nitz"

/**
 * Property to set multi sim feature.
 * Type:  String(dsds, dsda)
 */
#define PROPERTY_MULTI_SIM_CONFIG "persist.radio.multisim.config"

/**
 * Property to indicate if reboot is required when changing modems configurations
 * Type:  String(true, false) default is false  most devices don't need reboot
 */
#define PROPERTY_REBOOT_REQUIRED_ON_MODEM_CHANGE "persist.radio.reboot_on_modem_change"

/**
 * Property to store default subscription.
 */
#define PROPERTY_DEFAULT_SUBSCRIPTION "persist.radio.default.sub"

/**
 * Property to enable MMS Mode.
 * Type: string ( default silent, enable to prompt )
 */
#define PROPERTY_MMS_TRANSACTION "mms.transaction"

/**
 * Set to the sim count.
 */
#define PROPERTY_SIM_COUNT "ro.telephony.sim.count"

/**
 * Controls audio route for video calls.
 * 0 - Use the default audio routing strategy.
 * 1 - Disable the speaker. Route the audio to Headset or Bluetooth
 *     or Earpiece, based on the default audio routing strategy.
 */
#define PROPERTY_VIDEOCALL_AUDIO_OUTPUT "persist.radio.call.audio.output"

/** 'true' if the carrier text from opportunistic subscription should be used to display
 * on UI.
 *
 */
#define DISPLAY_OPPORTUNISTIC_SUBSCRIPTION_CARRIER_TEXT_PROPERTY_NAME ="persist.radio.display_opportunistic_carrier"


#endif //THANOX_INTERNAL_TELEPHONYPROPS_H
